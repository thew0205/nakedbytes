from typing import cast
from code_implementation.cpp_code_generator_utils import get_cpp_type_name
from code_implementation.type_desc_holder import TypeDesc, get_type_desc_from_types_desc


def get_base_serializer_class_function() -> str:
    return """
namespace nakedbytes{
NAKEDBYTES_FORCE_INLINE size_t get_padding_size(size_t offset, uint16_t alignment)
{
    return (alignment - (offset % alignment)) % alignment;
}

template <typename T>
struct SerializeOffset
{
    uint16_t offset = 0;

    template<typename U = void>
    operator SerializeOffset<U>() const
    {
        SerializeOffset<U> ret;
        ret.offset = this->offset;
        return ret;
    }
};

template <typename T>
struct is_serializable_offset_Type : std::false_type
{
};
template <typename T>
struct is_serializable_offset_Type<SerializeOffset<T>> : std::true_type
{
};

struct Serializer
{

#define VERSION 1
#define OFFSET_SIZE 2

    unsigned char *_buffer = nullptr;
    uint16_t _buffer_size = 0;
    // uint16_t _current_offset = 0;
    uint16_t _tail_offset = 0;

    void init(uint16_t buffer_size, const uint16_t root_type_size, uint16_t root_type_alignment)
    {
        _buffer = reinterpret_cast<unsigned char *>(malloc(buffer_size));
        _buffer_size = buffer_size;
        *reinterpret_cast<uint16_t *>(&_buffer[OFFSET_SIZE]) = VERSION;

        _tail_offset = get_padding_size(OFFSET_SIZE * 2, root_type_alignment) + OFFSET_SIZE * 2 + root_type_size;
        make_buffer_adequate();
    }


    inline void make_buffer_adequate()
    {
        while (_buffer_size < _tail_offset)
        {
            _buffer = reinterpret_cast<unsigned char *>(realloc(_buffer, _buffer_size * 2));
            _buffer_size = _buffer_size * 2;
        }
    }

    SerializeOffset<String> serialize_string(const char *str)
    {
        SerializeOffset<String> str_offset;
        
        if (str == nullptr)
        {
            str_offset.offset = 0;
        }
        else
        {
            size_t len = strlen(str);
            _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

            make_buffer_adequate();
            str_offset.offset = _tail_offset;

            *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
            _tail_offset += OFFSET_SIZE;
            memcpy(&_buffer[_tail_offset], str, len);
            *reinterpret_cast<unsigned char *>(&(((unsigned char *)_buffer)[_tail_offset + len])) = 0;
            _tail_offset += len + 1;
        }
        return str_offset;
    }
    
    template <typename T>
    typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_enum<T>::value), SerializeOffset<T>>::type serialize_primitive(T data)
    {
        SerializeOffset<T> data_offset;
        _tail_offset += get_padding_size(_tail_offset, sizeof(T));

        make_buffer_adequate();
        data_offset.offset = _tail_offset;

        *reinterpret_cast<T *>(&_buffer[_tail_offset]) = data;

        return data_offset;
    }
    
    template <typename>
    struct extract_vector_type
    {
    };

    template <typename T, typename Alloc>
    struct extract_vector_type<std::vector<T, Alloc>>
    {
        using type = T;
    };

    template <typename Vec>
    using vec_inner_t = typename extract_vector_type<Vec>::type;

    template <typename T>
    typename std::enable_if<(std::is_integral<vec_inner_t<T>>::value || std::is_floating_point<vec_inner_t<T>>::value || std::is_enum<vec_inner_t<T>>::value), SerializeOffset<Vector<vec_inner_t<T>>>>::type serialize_vector(T data_array)
    {
        SerializeOffset<Vector<vec_inner_t<T>>> data_array_offset;
        size_t len = data_array.size();
        _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

        make_buffer_adequate();
        data_array_offset.offset = _tail_offset;

        *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
        _tail_offset += OFFSET_SIZE;
        memcpy(&_buffer[_tail_offset], data_array.data(), len * sizeof(vec_inner_t<T>));
        _tail_offset += len * sizeof(vec_inner_t<T>);
        return data_array_offset;
    }

    template <typename T>
    typename std::enable_if<(is_serializable_offset_Type<vec_inner_t<T>>::value), SerializeOffset<Vector<vec_inner_t<T>>>>::type serialize_vector(T data_array)
    {
        SerializeOffset<Vector<vec_inner_t<T>>> data_array_offset;
        size_t len = data_array.size();
        _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

        make_buffer_adequate();
        data_array_offset.offset = _tail_offset;

        *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
        _tail_offset += OFFSET_SIZE;

        for (uint16_t i = 0; i < len; i++)
        {
            *reinterpret_cast<uint16_t*>(&_buffer[_tail_offset]) = data_array[i].offset - _tail_offset;
            _tail_offset += OFFSET_SIZE;
        }
        return data_array_offset;
    }
};
}; //namespace nakedbytes
"""

def generate_struct_offset_struct_field_struct(type_desc: TypeDesc, type_def_generated: set[str]) -> str:
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
    type_def_generated: set[str] = set()
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive or type_desc.type_type == 'enum' or type_desc.type_type == 'union':
            continue
        ret_str += generate_struct_offset_struct_field_struct(type_desc, type_def_generated = type_def_generated, )
        
        ret_str += '\n\n'
    return ret_str

def generate_struct_serializer_fields(type_desc: TypeDesc, is_root_type: bool, additional_prefix: str, access_prefix: str) -> str:
    ret_str = ""
    
    for mem in type_desc.members:
        if mem.name.startswith('pad'):
            continue
        type_name = get_cpp_type_name(mem.type_desc)
        if mem.is_offset_type:
            ret_str += f"*reinterpret_cast<uint16_t *>(&(serializer->_buffer[{"current_offset" if is_root_type else "serializer->_tail_offset"} {additional_prefix} + {type_desc.name.upper()}_{mem.name.upper()}_OFFSET])) = {access_prefix}{mem.name}.offset - ({"current_offset" if is_root_type else "serializer->_tail_offset"} {additional_prefix} +{type_desc.name.upper()}_{mem.name.upper()}_OFFSET);\n"
        elif mem.type_desc.is_primitive or mem.type_desc.type_type == 'enum':
            ret_str += f"*reinterpret_cast<{type_name} *>(&(serializer->_buffer[{"current_offset" if is_root_type else "serializer->_tail_offset"} {additional_prefix} + {type_desc.name.upper()}_{mem.name.upper()}_OFFSET])) = {access_prefix}{mem.name};\n"
        elif mem.type_desc.type_type == 'struct':
            ret_str += "\n\n" + generate_struct_serializer_fields(mem.type_desc, is_root_type= is_root_type, additional_prefix= additional_prefix + f"  + {type_desc.name.upper()}_{mem.name.upper()}_OFFSET", access_prefix= access_prefix + f"{mem.name}.")
        
        else:
            raise ValueError("")
              
    return ret_str
            
def generate_serialization_function_parameters(type_desc: TypeDesc) -> str: 
    ret_str  = ""
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
            ret_str += f",\n const ::nakedbytes::SerializeOffset<{type_name}> {mem.name}"
        else:
            ret_str += f",\n const {type_name} {mem.name}"
    return ret_str 
          
def generate_offset_serialization_function(type_desc: TypeDesc) -> str:

    ret_str = ""
    ret_str += f"inline ::nakedbytes::SerializeOffset<{type_desc.name}> serialize_{type_desc.name.lower()}"
    ret_str += "(::nakedbytes::Serializer *const serializer"
    
    ret_str += generate_serialization_function_parameters(type_desc= type_desc)
    ret_str += "){\n"
    
    ret_str += f"::nakedbytes::SerializeOffset<{type_desc.name}> {type_desc.name.lower()}_offset;\n"
    ret_str += f"serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, {type_desc.name.upper()}_ALIGNMENT);\n"
    ret_str += "serializer->make_buffer_adequate();\n"
    ret_str += f"{type_desc.name.lower()}_offset.offset = serializer->_tail_offset;\n\n"
    
    if type_desc.type_type == 'class':
        ret_str += f"*reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + {type_desc.name.upper()}_MEMBER_SIZE_OFFSET])) = {type_desc.name.upper()}_SIZE;"
        
    ret_str += generate_struct_serializer_fields(type_desc, is_root_type= False, additional_prefix= "", access_prefix = "")
           
    ret_str += f"serializer->_tail_offset += {type_desc.name.upper()}_SIZE;"
    
    ret_str += "\n"
    ret_str += f"return {type_desc.name.lower()}_offset;\n"
    ret_str += "}"
    return ret_str

def get_all_types_offset_serialization_function(types_desc: set[TypeDesc]) -> str:
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive or type_desc.type_type == 'enum':
            continue
        ret_str += generate_offset_serialization_function(type_desc)
        
        ret_str += '\n\n'
    return ret_str



def generate_root_type_serialization_function(types_desc: 
    set[TypeDesc], root_type_name: str) -> str:
    ret_str = ""
    root_type_desc =cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc))
    ret_str += "inline unsigned char *"
    ret_str += f"serialize_{root_type_desc.name.lower()}_root"
    ret_str += "(::nakedbytes::Serializer *const serializer"
    
    ret_str += generate_serialization_function_parameters(type_desc=root_type_desc)
   
    ret_str += "){\n"
    
    ret_str += f"uint16_t current_offset = OFFSET_SIZE * 2 + ::nakedbytes::get_padding_size(OFFSET_SIZE * 2, {root_type_desc.name.upper()}_ALIGNMENT);\n"
    if root_type_desc.type_type == 'class':
        ret_str += f"*reinterpret_cast<int16_t *>(&(serializer->_buffer[current_offset + {root_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])) = {root_type_desc.name.upper()}_SIZE;"
    
    ret_str += '\n\n'
    
    ret_str += generate_struct_serializer_fields(root_type_desc, is_root_type= True, additional_prefix= "", access_prefix = "")
    ret_str += "\n"
           
    ret_str += "*reinterpret_cast<uint16_t*>(&(serializer->_buffer[0])) = serializer->_tail_offset;\n"
    ret_str += "\n"
    ret_str += "return serializer->_buffer;\n"
    ret_str += "}"
    
    return ret_str

def generate_serialize_vector_struct(type_desc: TypeDesc) -> str:
    ret_str = ""
    ret_str += f"inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<{type_desc.name}Struct>> "
    ret_str += f"serialize_vector_{type_desc.name.lower()}_struct("
    ret_str += f"::nakedbytes::Serializer *const serializer, std::vector<{type_desc.name}Struct> data_array){{\n"
    ret_str += f"::nakedbytes::SerializeOffset<::nakedbytes::Vector<{type_desc.name}Struct>> data_array_offset;\n"
    ret_str += "uint16_t len = data_array.size();\n"
    ret_str += "serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE);\n"
    ret_str += "serializer->make_buffer_adequate();\n"
    ret_str += "data_array_offset.offset = serializer->_tail_offset;\n"
    ret_str += "*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;\n"
    ret_str += "serializer->_tail_offset += OFFSET_SIZE;"
    ret_str += f"serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, {type_desc.name.upper()}_ALIGNMENT);"
    ret_str += "for (uint16_t i = 0; i < len; i++){"
    ret_str += generate_struct_serializer_fields(type_desc=type_desc, is_root_type= False, additional_prefix= f" + ({type_desc.name.upper()}_SIZE * i)", access_prefix = "data_array[i].")
    ret_str += f"serializer->_tail_offset += ({type_desc.name.upper()}_SIZE * len);\n"
    ret_str += "}"
    
    ret_str += "return data_array_offset;"
    ret_str += f"}}"
    return ret_str


def generate_all_types_serialize_vector_struct(types_desc: set[TypeDesc]) -> str :
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive or type_desc.type_type == 'enum':
            continue
        ret_str += generate_serialize_vector_struct(type_desc)
        
        ret_str += '\n\n'
    return ret_str