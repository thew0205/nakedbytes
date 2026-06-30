from typing import cast
from code_implementation.cpp_code_generator_utils import get_cpp_type_name, get_signed_offset_type, get_unsigned_offset_type
from code_implementation.type_desc_holder import TypeDesc, get_type_desc_from_types_desc


def get_base_serializer_class_function(offset_size: int) -> str:
    """
    Return the base serializer class function.
    
    Args:
        offset_size (int): The size of the offset type to be used.
        
    Returns:
        str: The base serializer class function.
    """
    return f"""
namespace nakedbytes{{
template <typename T>
struct SerializeOffset
{{
    // Offset relative to the start of the buffer
    {get_unsigned_offset_type(offset_size)} offset = 0;

    template<typename U = void>
    operator SerializeOffset<U>() const
    {{
        SerializeOffset<U> ret;
        ret.offset = this->offset;
        return ret;
    }}
}};

template <typename T>
struct is_serializable_offset_Type : std::false_type
{{
}};
template <typename T>
struct is_serializable_offset_Type<SerializeOffset<T>> : std::true_type
{{
}};

struct Serializer
{{
    unsigned char *_buffer = nullptr;
    {get_unsigned_offset_type(offset_size)} _buffer_size = 0;
    {get_unsigned_offset_type(offset_size)} _tail_offset = 0;

    void init({get_unsigned_offset_type(offset_size)} buffer_size, const uint16_t root_type_size, uint16_t root_type_alignment)
    {{
        _buffer = static_cast<unsigned char *>(malloc(buffer_size));
        _buffer_size = buffer_size;
        *reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&_buffer[OFFSET_SIZE]) = VERSION;

        _tail_offset = static_cast<uint16_t>(static_cast<{get_unsigned_offset_type(offset_size)}>(get_padding_size(OFFSET_SIZE * 2, root_type_alignment)) + static_cast<{get_unsigned_offset_type(offset_size)}>(OFFSET_SIZE) * 2 + static_cast<{get_unsigned_offset_type(offset_size)}>(root_type_size));
        make_buffer_adequate();
    }}


    inline void make_buffer_adequate()
    {{
        while (_buffer_size < _tail_offset)
        {{
            _buffer = reinterpret_cast<unsigned char *>(realloc(_buffer, _buffer_size * 2));
            _buffer_size = _buffer_size * 2;
        }}
    }}

    SerializeOffset<String> serialize_string(const char *str)
    {{
        SerializeOffset<String> str_offset;
        
        if (str == nullptr)
        {{
            str_offset.offset = 0;
        }}
        else
        {{
            {get_unsigned_offset_type(offset_size)} len = static_cast<{get_unsigned_offset_type(offset_size)}>(strlen(str));
            _tail_offset += static_cast<{get_unsigned_offset_type(offset_size)}>(get_padding_size(_tail_offset, OFFSET_SIZE));

            make_buffer_adequate();
            str_offset.offset = _tail_offset;

            *reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&_buffer[_tail_offset]) = len;
            _tail_offset += OFFSET_SIZE;
            memcpy(&_buffer[_tail_offset], str, len);
            *reinterpret_cast<unsigned char *>(&(((unsigned char *)_buffer)[_tail_offset + len])) = 0;
            _tail_offset += static_cast<{get_unsigned_offset_type(offset_size)}>(len + 1);
        }}
        return str_offset;
    }}
    
    template <typename T>
    typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_enum<T>::value), SerializeOffset<T>>::type serialize_primitive(T data)
    {{
        SerializeOffset<T> data_offset;
        _tail_offset += static_cast<{get_unsigned_offset_type(offset_size)}>(get_padding_size(_tail_offset, sizeof(T)));

        make_buffer_adequate();
        data_offset.offset = _tail_offset;

        *reinterpret_cast<T *>(&_buffer[_tail_offset]) = data;

        return data_offset;
    }}
    
    template <typename>
    struct extract_vector_type
    {{
    }};

    template <typename T, typename Alloc>
    struct extract_vector_type<std::vector<T, Alloc>>
    {{
        using type = T;
    }};

    template <typename Vec>
    using vec_inner_t = typename extract_vector_type<Vec>::type;

    template <typename T>
    typename std::enable_if<(std::is_integral<vec_inner_t<T>>::value || std::is_floating_point<vec_inner_t<T>>::value || std::is_enum<vec_inner_t<T>>::value), SerializeOffset<Vector<vec_inner_t<T>>>>::type serialize_vector(T data_array)
    {{
        SerializeOffset<Vector<vec_inner_t<T>>> data_array_offset;
        {get_unsigned_offset_type(offset_size)} len = static_cast<{get_unsigned_offset_type(offset_size)}>(data_array.size());
        _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

        make_buffer_adequate();

        *reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&_buffer[_tail_offset]) = len;
        _tail_offset += OFFSET_SIZE;

        _tail_offset += get_padding_size(_tail_offset, sizeof(vec_inner_t<T>));
        data_array_offset.offset = _tail_offset;

        memcpy(&_buffer[_tail_offset], data_array.data(), len * sizeof(vec_inner_t<T>));
        _tail_offset += len * sizeof(vec_inner_t<T>);
        return data_array_offset;
    }}

    template <typename T>
    typename std::enable_if<(is_serializable_offset_Type<vec_inner_t<T>>::value), SerializeOffset<Vector<vec_inner_t<T>>>>::type serialize_vector(T data_array)
    {{
        SerializeOffset<Vector<vec_inner_t<T>>> data_array_offset;
        {get_unsigned_offset_type(offset_size)} len = static_cast<{get_unsigned_offset_type(offset_size)}>(data_array.size());
        _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

        make_buffer_adequate();

        *reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&_buffer[_tail_offset]) = len;
        _tail_offset += OFFSET_SIZE;
        data_array_offset.offset = _tail_offset;

        for ({get_unsigned_offset_type(offset_size)} i = 0; i < len; i++)
        {{
            *reinterpret_cast<{get_unsigned_offset_type(offset_size)}*>(&_buffer[_tail_offset]) = data_array[i].offset - _tail_offset;
            _tail_offset += OFFSET_SIZE;
        }}
        return data_array_offset;
    }}
    
     void deinit()
        {{
            if (_buffer != nullptr)
            {{
                free(_buffer);
                _buffer = nullptr;
                _buffer_size = 0;
                _tail_offset = 0;
            }}
        }}

        ~Serializer()
        {{
            deinit();
        }} 
        
        const unsigned char *get_buffer() const
        {{
            return _buffer;
        }}

        size_t get_size() const
        {{
            return _tail_offset;
        }}
}};
}}; //namespace nakedbytes
"""

def generate_struct_offset_struct_field_struct(type_desc: TypeDesc, type_def_generated: set[str]) -> str:
    """
    Generate the struct offset struct field struct.
    
    Args:
        type_desc (TypeDesc): The type description.
        type_def_generated (set[str]): The set of type definitions that have already been generated.
        
    Returns:
        str: The struct offset struct field struct.
    """
    if type_desc.name in type_def_generated:
        return ''
    type_def_generated.add(type_desc.name)
    
    ret_str = ""
    ret_str = f"struct {type_desc.name}Struct {{\n"
    
    mem_str_type_definition = ''
    
    for mem in type_desc.members:
        if not mem.type_desc.is_primitive and not mem.type_desc.name in type_def_generated:
            mem_str_type_definition += generate_struct_offset_struct_field_struct(mem.type_desc, type_def_generated)
            
        if mem.name.startswith('pad'):
            continue
        
        type_name = get_cpp_type_name(mem.type_desc)
        if mem.type_desc.type_type == 'union':
            type_name = 'void'
        elif mem.type_desc.type_type == 'struct' and (not mem.type_desc.is_primitive) and (not mem.type_desc.name == 'string'):
            type_name = f"{type_name}Struct"
            
        if mem.is_array:
            type_name = f"::nakedbytes::Vector<{type_name}>"
            
        if mem.is_offset_type:
            ret_str += f"::nakedbytes::SerializeOffset<{type_name}> {mem.name};\n"
        else:
            ret_str += f"{type_name} {mem.name};\n"
    ret_str += f"}};\n"
    
    ret_str =  mem_str_type_definition + "\n\n" + ret_str
    return ret_str


def get_all_type_struct_offset_struct_field_struct(types_desc: set[TypeDesc]) -> str:
    """
    Generate the struct offset struct field struct for all the types in the types_desc.
    
    Args:
        types_desc (set[TypeDesc]): The set of type descriptions.
        
    Returns:
        str: The struct offset struct field struct for all the types in the types_desc.
    """
    type_def_generated: set[str] = set()
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive or type_desc.type_type == 'enum' or type_desc.type_type == 'union':
            continue
        ret_str += generate_struct_offset_struct_field_struct(type_desc, type_def_generated = type_def_generated, )
        
        ret_str += '\n\n'
    return ret_str

def generate_struct_serializer_fields(type_desc: TypeDesc, is_root_type: bool, additional_marco_offset_prefix: str, access_prefix: str, offset_size: int) -> str:
    """
    Generate the serialization lines that write each field of a struct into the serializer buffer.

    Args:
        type_desc (TypeDesc): The struct type description whose fields will be serialized.
        is_root_type (bool): If True, uses `current_offset` as the base offset variable;
            otherwise uses `serializer->_tail_offset`.
        additional_marco_offset_prefix (str): Extra offset expression appended to the macro
            offset, used to locate the field relative to its parent struct.
        access_prefix (str): Extra accessor prefix used to reach the field in the parent object
            (e.g. `"member_name."`)
        offset_size (int): The offset size for the project.

    Returns:
        str: The generated C++ code that serializes each field of the struct.
    """
    ret_str = ""
    
    for mem in type_desc.members:
        if mem.name.startswith('pad'):
            continue
        type_name = get_cpp_type_name(mem.type_desc)
        if mem.is_offset_type:
            # This is to generate this
            # *reinterpret_cast<int16_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET])) = static_cast<int16_t>(group.id.offset - (current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET));
            ret_str += f"*reinterpret_cast<{get_signed_offset_type(offset_size)}  *>(&({"this" if is_root_type else "serializer"}->_buffer[{"current_offset" if is_root_type else "serializer->_tail_offset"} {additional_marco_offset_prefix} + {type_desc.name.upper()}_{mem.name.upper()}_OFFSET])) = static_cast<{get_signed_offset_type(offset_size)} >({access_prefix}{mem.name}.offset - ({"current_offset" if is_root_type else "serializer->_tail_offset"} {additional_marco_offset_prefix} +{type_desc.name.upper()}_{mem.name.upper()}_OFFSET));\n"
        elif mem.type_desc.is_primitive or mem.type_desc.type_type == 'enum':
            ret_str += f"*reinterpret_cast<{type_name} *>(&({"this" if is_root_type else "serializer"}->_buffer[{"current_offset" if is_root_type else "serializer->_tail_offset"} {additional_marco_offset_prefix} + {type_desc.name.upper()}_{mem.name.upper()}_OFFSET])) = static_cast<{type_name}>({access_prefix}{mem.name});\n"
        elif mem.type_desc.type_type == 'struct':
            ret_str += "\n\n" + generate_struct_serializer_fields(mem.type_desc, is_root_type= is_root_type, additional_marco_offset_prefix= additional_marco_offset_prefix + f"  + {type_desc.name.upper()}_{mem.name.upper()}_OFFSET", access_prefix= access_prefix + f"{mem.name}.", offset_size= offset_size)
        
        else:
            raise ValueError("")
              
    return ret_str
            
def generate_serialization_function_parameters(type_desc: TypeDesc, prepend_comma: bool) -> str: 
    """
    Generate the serialization function parameters.
    
    Args:
        type_desc (TypeDesc): The type description.
        prepend_comma (bool): If the first parameter should be prepended with a comma.
        
    Returns:
        str: The serialization function parameters.
    """
    ret_str  = ""
    if prepend_comma:
        ret_str += ","
    for mem in type_desc.members:
        if mem.name.startswith('pad'):
            continue
        type_name = get_cpp_type_name(mem.type_desc)
        if mem.type_desc.type_type == 'union':
            type_name = 'void'
        elif mem.type_desc.type_type == 'struct' and (not mem.type_desc.is_primitive) and (not mem.type_desc.name == 'string'):
            type_name = f"{type_name}Struct"

            
        if mem.is_array:
            if mem.type_desc.is_offset_type:
                type_name = f"::nakedbytes::SerializeOffset<{type_name}>"
            type_name = f"::nakedbytes::Vector<{type_name}>"
            
        if mem.is_offset_type:
            ret_str += f"\n const ::nakedbytes::SerializeOffset<{type_name}> {mem.name},"
        else:
            ret_str += f"\n const {type_name} {mem.name},"
    return ret_str [:-1]  # remove last comma
          
def generate_offset_serialization_function(type_desc: TypeDesc, offset_size: int) -> str:
    """
    Generate the offset serialization function.
    
    Args:
        type_desc (TypeDesc): The type description.
        offset_size (int): The offset size for the project.
        
    Returns:
        str: The offset serialization function.
    """
    ret_str = ""
    ret_str += f"inline ::nakedbytes::SerializeOffset<{type_desc.name}> serialize_{type_desc.name.lower()}"
    ret_str += "(::nakedbytes::Serializer *const serializer"
    
    ret_str += generate_serialization_function_parameters(type_desc= type_desc, prepend_comma= True)
    ret_str += "){\n"
    
    ret_str += f"::nakedbytes::SerializeOffset<{type_desc.name}> {type_desc.name.lower()}_offset;\n"
    ret_str += f"serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, {type_desc.name.upper()}_ALIGNMENT);\n"
    ret_str += "serializer->make_buffer_adequate();\n"
    ret_str += f"{type_desc.name.lower()}_offset.offset = serializer->_tail_offset;\n\n"
    
    if type_desc.type_type == 'class':
        ret_str += f"*reinterpret_cast<{get_signed_offset_type(offset_size)}  *>(&(serializer->_buffer[serializer->_tail_offset + {type_desc.name.upper()}_MEMBER_SIZE_OFFSET])) = {type_desc.name.upper()}_SIZE;"
        
    ret_str += generate_struct_serializer_fields(type_desc, is_root_type= False, additional_marco_offset_prefix= "", access_prefix = "", offset_size= offset_size)
           
    ret_str += f"serializer->_tail_offset += {type_desc.name.upper()}_SIZE;"
    
    ret_str += "\n"
    ret_str += f"return {type_desc.name.lower()}_offset;\n"
    ret_str += "}"
    return ret_str

def get_all_types_offset_serialization_function(types_desc: set[TypeDesc], offset_size: int) -> str:
    """
    Generate the offset serialization function for all the types in the types_desc.
    
    Args:
        types_desc (set[TypeDesc]): The set of type descriptions.
        offset_size (int): The offset size for the project.
        
    Returns:
        str: The offset serialization function.
    """
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive or type_desc.type_type == 'enum':
            continue
        ret_str += generate_offset_serialization_function(type_desc, offset_size= offset_size)
        
        ret_str += '\n\n'
    return ret_str



def generate_root_type_serialization_class(types_desc: set[TypeDesc], root_type_name: str, offset_size: int) -> str:
    """
    Generate a C++ serializer class for the root type.

    The generated class inherits from `::nakedbytes::Serializer` and exposes an
    `init()` method (which pre-allocates the buffer sized to the root type) and a
    `serialize_root()` method that writes all root-type fields directly into the
    buffer at a fixed offset.

    Args:
        types_desc (set[TypeDesc]): The full set of resolved type descriptions.
        root_type_name (str): The name of the root type to generate a serializer for.
        offset_size (int): The offset size for the project.

    Returns:
        str: The generated C++ class definition as a string.
    """
    ret_str = ""
    root_type_desc =cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc))
    ret_str += f"struct {root_type_desc.name}Serializer : public ::nakedbytes::Serializer{{\n"
    
   
    ret_str += f"    void init({get_unsigned_offset_type(offset_size)} buffer_size){{\n"
    ret_str += f"        ::nakedbytes::Serializer::init(buffer_size, {root_type_desc.name.upper()}_SIZE, {root_type_desc.name.upper()}_ALIGNMENT);\n"
    ret_str += f"    }}\n\n"
    ret_str += f"    inline {get_unsigned_offset_type(offset_size)} serialize_root("
    ret_str += generate_serialization_function_parameters(type_desc= root_type_desc, prepend_comma= False)
    ret_str += f"){{\n"
    ret_str += f"        {get_unsigned_offset_type(offset_size)} current_offset = static_cast<{get_unsigned_offset_type(offset_size)}>(OFFSET_SIZE * 2 + ::nakedbytes::get_padding_size(OFFSET_SIZE * 2, {root_type_desc.name.upper()}_ALIGNMENT));\n"
    if root_type_desc.type_type == 'class':
        ret_str += f"        *reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&(this->_buffer[current_offset + {root_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])) = static_cast<{get_unsigned_offset_type(offset_size)}>({root_type_desc.name.upper()}_SIZE);\n"


    ret_str += generate_struct_serializer_fields(root_type_desc, is_root_type= True, additional_marco_offset_prefix= "", access_prefix = "", offset_size= offset_size)
    ret_str += "\n"
           
    ret_str += f"*reinterpret_cast<{get_unsigned_offset_type(offset_size)}*>(&(this->_buffer[0])) = this->_tail_offset;\n"
    ret_str += "\n"
    ret_str += "return this->_tail_offset;\n"
    ret_str += f"}}"
    
    ret_str += f"}};\n\n"

    
    return ret_str

def generate_serialize_vector_struct(type_desc: TypeDesc, offset_size: int) -> str:
    """
    Generate a C++ helper function that serializes a `std::vector` of a given struct type
    into the nakedbytes buffer.

    The generated function writes the element count followed by the serialized fields of
    each element contiguously, respecting alignment requirements.

    Args:
        type_desc (TypeDesc): The type description of the struct element type.
        offset_size (int): The offset size for the project.

    Returns:
        str: The generated C++ inline function definition as a string.
    """
    ret_str = ""
    ret_str += f"inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<{type_desc.name}Struct>> "
    ret_str += f"serialize_vector_{type_desc.name.lower()}_struct("
    ret_str += f"::nakedbytes::Serializer *const serializer, std::vector<{type_desc.name}Struct> data_array){{\n"
    ret_str += f"::nakedbytes::SerializeOffset<::nakedbytes::Vector<{type_desc.name}Struct>> data_array_offset;\n"
    ret_str += f"{get_unsigned_offset_type(offset_size)} len = static_cast<{get_unsigned_offset_type(offset_size)}>(data_array.size());\n"
    ret_str += f"serializer->_tail_offset += static_cast<{get_unsigned_offset_type(offset_size)}>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));\n"
    ret_str += "serializer->make_buffer_adequate();\n"
    ret_str += f"*reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&serializer->_buffer[serializer->_tail_offset]) = len;\n"
    ret_str += "serializer->_tail_offset += OFFSET_SIZE;"
    ret_str += f"serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, {type_desc.name.upper()}_ALIGNMENT);"
    ret_str += "data_array_offset.offset = serializer->_tail_offset;\n"
    ret_str += f"for ({get_unsigned_offset_type(offset_size)} i = 0; i < len; i++){{"
    ret_str += generate_struct_serializer_fields(type_desc=type_desc, is_root_type= False, additional_marco_offset_prefix= f" + ({type_desc.name.upper()}_SIZE * i)", access_prefix = "data_array[i].", offset_size= offset_size)
    ret_str += f"serializer->_tail_offset += static_cast<{get_unsigned_offset_type(offset_size)}>({type_desc.name.upper()}_SIZE * len);\n"
    ret_str += "}"
    
    ret_str += "return data_array_offset;"
    ret_str += f"}}"
    return ret_str


def generate_all_types_serialize_vector_struct(types_desc: set[TypeDesc], offset_size: int) -> str:
    """
    Generate C++ vector-serialization helper functions for every non-primitive,
    non-enum type in the provided set.

    Iterates over `types_desc`, skipping primitive and enum types, and calls
    `generate_serialize_vector_struct` for each eligible type.

    Args:
        types_desc (set[TypeDesc]): The full set of resolved type descriptions.
        offset_size (int): The offset size for the project.

    Returns:
        str: The concatenated C++ function definitions as a string.
    """
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive or type_desc.type_type == 'enum':
            continue
        ret_str += generate_serialize_vector_struct(type_desc, offset_size= offset_size)
        
        ret_str += '\n\n'
    return ret_str