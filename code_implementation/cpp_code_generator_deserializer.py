from typing import List, cast
from code_implementation.type_desc_holder import MemberDesc, TypeDesc, get_type_desc_from_types_desc


def get_header_files() -> str:
    return '''
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <type_traits>
#include <vector>

#define OFFSET_SIZE 2

'''

def get_base_offset_types() -> str:
    return '''



struct String
{
    unsigned char *data;

    String(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
#define STRING_LENGTH_OFFSET 0
    uint16_t length() const
    {
        int16_t offset = STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *c_str() const
    {
        uint16_t offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }
};

template<typename T, typename Enable = void>
struct Offset
{
    unsigned char *data;
    Offset(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }

    T value() const
    {
        int16_t offset = *reinterpret_cast<int16_t *>(&data[0]);
        return T(&data[offset]);
    }
};

template<typename T>
struct Offset<T, typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value)>::type>
{
    unsigned char *data;
    Offset(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }

    T value() const
    {
        int16_t offset = *reinterpret_cast<int16_t *>(&data[0]);
        return static_cast<T>(data[offset]);
    }
};

template<typename T> struct is_Offset_Type : std::false_type {};
template<typename T>
struct is_Offset_Type<Offset<T>> : std::true_type {};


template <typename T>
struct Union
{
    unsigned char *data;
    Union(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define UNION_TYPE_OFFSET 0
    uint16_t type() const
    {
        return *reinterpret_cast<uint16_t *>(&data[UNION_TYPE_OFFSET]);
    }

#define DATA_OFFSET 2
    const unsigned char *raw_data() const
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) + DATA_OFFSET;

        return (&data[offset]);
    }
    
    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) == 0;
    }
};

template<typename T, typename Enable = void>
struct Vector
{
    unsigned char *data;

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }
    
    uint16_t size() const
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index) const
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + OFFSET_SIZE * index;
       

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};

template<typename T>
struct Vector<T, typename std::enable_if<(std::is_floating_point<T>::value || std::is_integral<T>::value || is_Offset_Type<T>::value)>::type>
{
    unsigned char *data;

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }
    
    uint16_t size() const
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index) const
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + OFFSET_SIZE * index;
       

        return static_cast<T>(data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};

'''



def get_base_serializer_class_function() -> str:
    return """

size_t get_padding_size(size_t offset, uint16_t alignment)
{
    return (alignment - (offset % alignment)) % alignment;
}

template <typename T>
struct SerializeOffset
{
    uint16_t offset = 0;

    operator SerializeOffset<void>() const
    {
        return SerializeOffset<void>{.offset = offset};
    }
};

struct Serializer
{

#define VERSION 1
#define OFFSET_SIZE 2

    unsigned char *_buffer = nullptr;
    uint16_t _buffer_size = 0;
    // uint16_t _current_offset = 0;
    uint16_t _tail_offset = 0;

    void init(uint16_t buffer_size)
    {
        _buffer = reinterpret_cast<unsigned char *>(malloc(buffer_size));
        _buffer_size = buffer_size;
        // _current_offset += OFFSET_SIZE;
        *reinterpret_cast<uint16_t *>(&_buffer[OFFSET_SIZE]) = VERSION;
        // _current_offset += OFFSET_SIZE;
        // _current_offset += get_padding_size(_current_offset, PACKET_ALIGNMENT);

        _tail_offset = get_padding_size(OFFSET_SIZE * 2, PACKET_ALIGNMENT) + OFFSET_SIZE * 2 + PACKET_SIZE;
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
    
    template <typename T>
    typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_enum<T>::value || is_Offset_Type<T>::value), SerializeOffset<Vector<T>>>::type serialize_vector(std::vector<T> data_array)
    {
        SerializeOffset<Vector<T>> data_array_offset;
        size_t len = data_array.size();
        _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

        make_buffer_adequate();
        data_array_offset.offset = _tail_offset;

        *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
        _tail_offset += OFFSET_SIZE;
        memcpy(&_buffer[_tail_offset], data_array.data(), len * sizeof(T));
        _tail_offset += len * sizeof(T);
        return data_array_offset;
    }
};
"""
def convert_to_cpp_primitive_type(type_name: str) -> str:
    if type_name == 'bool':
        return 'bool'
    elif type_name == 'uint8':
        return 'uint8_t'
    elif type_name == 'int8':
        return 'int8_t'
    elif type_name == 'uint16':
        return 'uint16_t'
    elif type_name == 'int16':
        return 'int16_t'
    elif type_name == 'uint32':
        return 'uint32_t'
    elif type_name == 'int32':
        return 'int32_t'
    elif type_name == 'uint64':
        return 'uint64_t'
    elif type_name == 'int64':
        return 'int64_t'
    elif type_name == 'float32':
        return 'float'
    elif type_name == 'float64':
        return 'double'
    elif type_name == 'char':
        return 'char'
    elif type_name == 'string':
        return "const char *"
    else:
        raise ValueError(f"Primitive type {type_name} not supported yet.")

def kind_of_struct(type_desc: TypeDesc) -> bool:
    return type_desc.type_type in ['struct', 'struct_offset', 'class']


def generate_struct_enum_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ""
    ret_str += f"{mem.type_desc.name} {mem.name}() const {{"
    ret_str += '\n'
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        ret_str += '\n'
        
    ret_str += f"return *reinterpret_cast<{mem.type_desc.name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2 * OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
        ret_str += '\n'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_primitive_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ""
    type_name = convert_to_cpp_primitive_type(mem.type_desc.name)
    ret_str += f"{type_name} {mem.name}() const {{"
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        ret_str += '\n'
        
    ret_str += f"return *reinterpret_cast<{type_name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
        ret_str += '\n'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_string_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'Offset<String> {mem.name}() const {{'
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        ret_str += '\n'
        
        
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += '\n'
    
    ret_str += 'return Offset<String>(&data_[offset]);'
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
        ret_str += '\n'
    ret_str += f"}}"
    return ret_str
    
def generate_struct_vector_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    
    if mem.type_desc.is_offset_type:
        if mem.type_desc.type_type == 'union':
            type_name = f'{mem.type_desc.name}'
        elif mem.type_desc.name == 'string':
            type_name = f'Offset<String>'
        elif mem.type_desc.type_type in ['struct_offset', 'class']:
            type_name = f'Offset<{mem.type_desc.name}>'
        else:
            raise ValueError('')
    elif mem.type_desc.is_primitive:
        type_name = convert_to_cpp_primitive_type(mem.type_desc.name)
    elif mem.type_desc.type_type == 'enum':
        type_name = f'{mem.type_desc.name}'
    elif mem.type_desc.type_type == 'struct':
        type_name = f'{mem.type_desc.name}'
    else:
            raise ValueError('')
        
            
        
    ret_str += f'Vector<{type_name}> {mem.name}() const {{'
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        ret_str += '\n'
        
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += '\n'
    
    ret_str += f'return Vector<{type_name}>(&data_[offset]);'
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
        ret_str += '\n'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_union_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'{mem.type_desc.name} {mem.name}() const {{'
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        ret_str += '\n'
        
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET - 2 {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += '\n'
    
    ret_str += f'return {mem.type_desc.name}(&data_[offset]);'
    ret_str += '\n'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
        ret_str += '\n'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_class_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'Offset<{mem.type_desc.name}> {mem.name}() const {{'
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f'const int16_t offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return Offset<{mem.type_desc.name}>(&data_[offset]);'
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
    ret_str += f"}}"
    return ret_str

def generate_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    if mem.is_array:
        return generate_struct_vector_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type == 'union':
        return generate_struct_union_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.name == 'string':
        return generate_struct_string_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type in ['struct_offset', 'class']: 
        return generate_struct_class_struct_offset_member_get_function(mem, parent_type_desc, is_root_type)
    else:
        raise ValueError(f"Type of {mem.type_desc.name} is not an offset type")
    
def generate_struct_struct_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = f'{mem.type_desc.name} {mem.name}() const {{'
    ret_str += f'return {mem.type_desc.name}(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}]);'
    ret_str += f"}}"
    return ret_str
       
def generate_struct_class_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ""
    if mem.is_offset_type:
        ret_str += generate_struct_offset_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.is_primitive:
        ret_str += generate_struct_primitive_number_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type == 'enum':
        ret_str += generate_struct_enum_number_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type == 'struct':
        ret_str += generate_struct_struct_member_get_function(mem, parent_type_desc, is_root_type)
    return ret_str



  #     StringOffset id()
    # {

    #     if (SUNSPECPOINTDEF_ID_OFFSET < *reinterpret_cast<uint16_t *>(&data_[0]))
    #     {
    #         const int16_t offset = SUNSPECPOINTDEF_ID_OFFSET;
    #         return StringOffset(&data_[offset]);
    #     }
    # }


def generate_class_enum_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ""
    ret_str += f"{mem.type_desc.name} {mem.name}() {{"
    
    ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f"return *reinterpret_cast<{mem.type_desc.name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2 * OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += f'}}'
   
    ret_str += f"}}"
    return ret_str

def generate_class_primitive_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ""
    type_name = convert_to_cpp_primitive_type(mem.type_desc.name)
    
    ret_str += f"{type_name} {mem.name}() {{"
    
    ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f"return *reinterpret_cast<{type_name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2 * OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += f'}}'
   
    ret_str += f"}}"
    
    return ret_str

def generate_class_string_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'StringOffset {mem.name}(){{'
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += 'return StringOffset(&data_[offset]);'
    ret_str += f"}}"
    return ret_str
    
def generate_class_vector_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    
    if mem.type_desc.is_offset_type:
        if mem.type_desc.type_type == 'union':
            type_name = f'Union<{mem.type_desc.name}>'
        elif mem.type_desc.name == 'string':
            type_name = f'StringOffset'
        elif mem.type_desc.type_type == 'struct_offset':
            type_name = f'{mem.type_desc.name}Offset'
        elif mem.type_desc.type_type == 'class':
            type_name = f'{mem.type_desc.name}'
        else:
            raise ValueError('')
    elif mem.type_desc.is_primitive:
        type_name = convert_to_cpp_primitive_type(mem.type_desc.name)
    elif mem.type_desc.type_type == 'struct':
        type_name = f'{mem.type_desc.name}'
    else:
            raise ValueError('')
        
            
        
    ret_str += f'Vector<{type_name}> {mem.name}(){{'
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return Vector<{type_name}>(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_union_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'Union<{mem.type_desc.name}> {mem.name}(){{'
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET - 2;'
    ret_str += f'return Union<{mem.type_desc.name}>(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'{mem.type_desc.name}Offset {mem.name}(){{'
    ret_str += f'const int16_t offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return {mem.type_desc.name}Offset(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_class_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'{mem.type_desc.name} {mem.name}(){{'
    ret_str += f'const int16_t offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return {mem.type_desc.name}Offset(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    if mem.is_array:
        return generate_class_vector_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type == 'union':
        return generate_class_union_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.name == 'string':
        return generate_class_string_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type == 'struct_offset':
        
        return generate_class_struct_offset_member_get_function(mem, parent_type_desc, is_root_type)
    
    elif mem.type_desc.type_type == 'class':
        return generate_class_class_member_get_function(mem, parent_type_desc, is_root_type)
    else:
        raise ValueError(f"Type of {mem.type_desc.name} is not an offset type")
    
def generate_class_struct_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = f'{mem.type_desc.name} {mem.name}(){{'
    ret_str += f'return {mem.type_desc.name}(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}]);'
    ret_str += f"}}"
    return ret_str
       



def generate_constructor(type_desc: TypeDesc) -> str:
    if type_desc.is_primitive or type_desc.type_type == 'enum':
        raise ValueError("Only struct, struct_offset and class can have constructor")
    ret_str = f"{type_desc.name}(unsigned char * data) : data_(data) {{}}"
    return ret_str
    
def generate_define_offset_macro(type_desc: TypeDesc) -> str:
    ret_str = ""
    for mem in type_desc.members:
        ret_str += f"#define {type_desc.name.upper()}_{mem.name.upper()}_OFFSET {mem.offset}\n"
    ret_str += f"#define {type_desc.name.upper()}_ALIGNMENT {type_desc.alignment}\n"
    ret_str += f"#define {type_desc.name.upper()}_SIZE {type_desc.size}\n"
    return ret_str

def generate_enum_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    ret_str = ''
    ret_str += f'enum {type_desc.name} : {convert_to_cpp_primitive_type(type_desc.basetype.name)} {{'
    ret_str += '\n\n'
    
    for e_mem in type_desc.e_members:
        ret_str += f'{e_mem.name},'
        ret_str += '\n'
        
    ret_str += f'}};'
    
    ret_str += '\n\n'
    
    ret_str += 'const char * '
    ret_str += f'{type_desc.name}_to_string({type_desc.name} value){{\n'
    ret_str += 'switch (value){\n'
    
    for e_mem in type_desc.e_members:
        ret_str += f'case {e_mem.name}:\n'
        ret_str += f'return "{e_mem.name}";\n'
    
        
    ret_str += 'default:\nreturn NULL;\n'
    ret_str += '}\n'
    ret_str += f'}}\n'
    
    return ret_str



# template <typename T>
# struct Union
# {
#     unsigned char *data;
#     Union(unsigned char *dataPtr)
#     {
#         data = dataPtr;
#     }

# #define UNION_TYPE_OFFSET 0
#     uint16_t type()
#     {
#         return *reinterpret_cast<uint16_t *>(&data[UNION_TYPE_OFFSET]);
#     }

# #define DATA_OFFSET 2
#     unsigned char *raw_data()
#     {
#         int16_t offset = *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) + DATA_OFFSET;

#         return (&data[offset]);
#     }
    
#     bool is_null()
#     {
#         return *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) == 0;
#     }
# };
def generate_union_type_access_primitive_definition(type_desc: TypeDesc, parent_type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    ret_str = ''
    type_name = convert_to_cpp_primitive_type(type_desc.name)
    ret_str += f'{type_name} data_as_{type_desc.name}() const {{\n'
    ret_str += f'return type() == {parent_type_desc.name}_enum_{type_desc.name} ? *reinterpret_cast<{type_name} *>(raw_data()) : 0;\n'
    ret_str += f'}}'
    return ret_str

def generate_union_type_access_enum_definition(type_desc: TypeDesc, parent_type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    ret_str = ''
    ret_str += f'{type_desc.name} data_as_{type_desc.name}() const{{\n'
    ret_str += f'return type() == {parent_type_desc.name}_enum_{type_desc.name} ? *reinterpret_cast<{type_desc.name} *>(raw_data()) : 0;\n'
    ret_str += f'}}'
    
    return ret_str

def generate_union_type_access_struct_definition(type_desc: TypeDesc, parent_type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    ret_str = ''
    ret_str += f'{type_desc.name} data_as_{type_desc.name}() const {{\n'
    ret_str += f'return type() == {parent_type_desc.name}_enum_{type_desc.name} ? {type_desc.name}(raw_data()) : 0;\n'
    ret_str += f'}}'
    
    return ret_str


def get_cpp_type_name(type_desc: TypeDesc)-> str:
    if type_desc.name == 'string':
        type_name = 'String'
    elif type_desc.is_primitive:
        type_name = convert_to_cpp_primitive_type(type_desc.name)
    # elif type_desc.type_type in  ['struct_offset', 'class']:
        # type_name = type_desc.name
    
    else:
        type_name = type_desc.name
    return type_name

def generate_union_type_access_offset_type_definition(type_desc: TypeDesc, parent_type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    type_name = get_cpp_type_name(type_desc)
        
        # raise ValueError(f"Type of {type_desc.name} is not an offset type")
    ret_str = ''
    ret_str += f'Offset<{type_name}> data_as_{type_desc.name}() const {{\n'
    ret_str += f'return type() == {parent_type_desc.name}_enum_{type_desc.name} ? Offset<{type_name}>(&data_[{parent_type_desc.name.upper()}_DATA_OFFSET]) : 0;\n'
    ret_str += f'}}'
    
    return ret_str
    
def generate_union_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str], types_desc: set[TypeDesc], ) -> str:
    
    ret_str = ''
    ret_str += f'struct {type_desc.name}{{'
    ret_str += '\n\n'
    ret_str += f"unsigned char * data_;"
    ret_str += '\n\n'
    ret_str += generate_constructor(type_desc)
    ret_str += '\n\n'
    ret_str += f'#define {type_desc.name.upper()}_TYPE_OFFSET 0\n'
    ret_str += f'#define {type_desc.name.upper()}_DATA_OFFSET 2\n'
    ret_str += f"#define {type_desc.name.upper()}_ALIGNMENT {type_desc.alignment}\n"
    ret_str += f"#define {type_desc.name.upper()}_SIZE {type_desc.size}\n"
    ret_str += '\n\n'
    

    
    ret_str += 'bool is_null() const {\n'
    ret_str += f'return (type() == 0) or (*reinterpret_cast<uint16_t *>(&data_[{type_desc.name.upper()}_DATA_OFFSET]) == 0);\n'
    ret_str += '}'
    ret_str += '\n\n'
    
    ret_str += 'unsigned char *raw_data() const {'
    ret_str += f'const int16_t offset = *reinterpret_cast<uint16_t *>(&data_[{type_desc.name.upper()}_DATA_OFFSET]) + {type_desc.name.upper()}_DATA_OFFSET;\n'
    ret_str += f'return (&data_[offset]);\n'
    ret_str += '}\n'
    
    mem_str_type_definition = ''
    if not f'{type_desc.name}_enum' in type_def_generated:
            mem_str_type_definition += generate_type_definition(type_desc = cast(TypeDesc, get_type_desc_from_types_desc(f'{type_desc.name}_enum' , types_desc)),is_root_type= False, type_def_generated= type_def_generated, types_desc= types_desc)
        
    
    ret_str += f'{type_desc.name}_enum type() const {{\n'
    ret_str += f'return *reinterpret_cast<{type_desc.name}_enum *>(&data_[{type_desc.name.upper()}_TYPE_OFFSET]);\n'
    ret_str += f'}}'
    ret_str += '\n\n'
    
    for u_type_desc in type_desc.u_members:
        if not u_type_desc.is_primitive and not u_type_desc.name in type_def_generated:
            mem_str_type_definition += generate_type_definition(type_desc = u_type_desc, is_root_type =False, type_def_generated= type_def_generated, types_desc= types_desc)
        ret_str += generate_union_type_access_offset_type_definition(u_type_desc, type_desc, is_root_type,type_def_generated)
                   
        ret_str += '\n\n'
        
    ret_str += f'}};'
    
    ret_str =  mem_str_type_definition + '\n\n' + ret_str
    ret_str += '\n\n'
    

    
    return ret_str
        
def generate_struct_offset_struct_class_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str], types_desc: set[TypeDesc]) -> str:
    ret_str = ''
    ret_str += f"struct {type_desc.name} {{"
    ret_str += '\n\n'
    ret_str += f"unsigned char * data_;"
    ret_str += '\n\n'
    ret_str += generate_constructor(type_desc)
    ret_str += '\n\n'
    if type_desc.type_type == 'class':
        ret_str += f"#define {type_desc.name.upper()}_MEMBER_SIZE_OFFSET 0\n"
    ret_str += generate_define_offset_macro(type_desc)
    ret_str += '\n\n'
    
    mem_str_type_definition = ''
    for mem in type_desc.members:
        if mem.name.startswith('pad'):
            continue
        if not mem.type_desc.is_primitive and not mem.type_desc.name in type_def_generated:
            mem_str_type_definition += generate_type_definition(type_desc = mem.type_desc, is_root_type= False, type_def_generated= type_def_generated, types_desc= types_desc)
        ret_str += generate_struct_class_member_get_function(mem, type_desc, is_root_type)
        ret_str += '\n\n'
        
    ret_str += f"}};"
    ret_str += '\n\n'
    
    ret_str =  mem_str_type_definition + '\n\n' + ret_str
    ret_str += '\n\n'
    
    if type_desc.type_type in ['struct_offset', 'class']:
        ret_str += generate_type_definition_of_struct_offset_type(type_desc)
    return ret_str



def generate_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str], types_desc: set[TypeDesc], ) -> str:
    if type_desc.name in type_def_generated:
        return ''
    type_def_generated.add(type_desc.name)
    
    ret_str = ''
    if type_desc.is_primitive:
        raise ValueError(f'Type of {type_desc.name} is a primitive type Type definition cannot to be generated.')
    
    elif type_desc.type_type == 'enum':           
        ret_str += generate_enum_type_definition(type_desc=type_desc, is_root_type=is_root_type, type_def_generated=type_def_generated)
        #? A union can't be a root type
    elif type_desc.type_type == 'union':
        if is_root_type == True:
            raise ValueError("A union type can be the root type")
        ret_str += generate_union_type_definition(type_desc=type_desc, is_root_type=is_root_type, type_def_generated=type_def_generated, types_desc= types_desc)
    elif type_desc.type_type in ['struct', 'struct_offset', 'class']:
        ret_str += generate_struct_offset_struct_class_type_definition(type_desc=type_desc, is_root_type= is_root_type, type_def_generated= type_def_generated, types_desc= types_desc)
    return ret_str

def generate_type_definition_of_struct_offset_type(type_desc: TypeDesc) -> str:
    ret_str = f"struct {type_desc.name}Offset {{"
    ret_str += '\n\n'
    ret_str += f"unsigned char * data_;"
    ret_str += '\n\n'
    ret_str += f"{type_desc.name}Offset (unsigned char * data) : data_(data) {{}}"
    ret_str += '\n\n'
    ret_str += '''
     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    '''
    ret_str += '\n\n'
    ret_str += f'{type_desc.name} value(){{\n'
    ret_str += ' const int16_t offset = *reinterpret_cast<int16_t *>(data_);\n'
    ret_str += f'return {type_desc.name}(&data_[offset]);\n'
    ret_str += f"}}\n"
    
    ret_str += f"}};"
    return ret_str

def get_all_type_definition(types_desc: set[TypeDesc], root_type_name: str, defined_type: List[str]) -> str:
    type_def_generated: set[str] = set()
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive:
            continue
        ret_str += generate_type_definition(type_desc, is_root_type= type_desc.name == root_type_name, type_def_generated = type_def_generated, types_desc= types_desc)
        
        ret_str += '\n\n'
    return ret_str

def get_all_type_declaration(types_desc: set[TypeDesc]) -> str:
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive:
            continue
        if type_desc.type_type == 'enum':
            continue
        else:
            ret_str += f"struct {type_desc.name}; \n"
    return ret_str

def generate_offset_serialization_function(type_desc: TypeDesc) -> str:

    ret_str = ""
    ret_str += f"SerializeOffset<{type_desc.name}> serialize_{type_desc.name.lower()}"
    ret_str += "(Serializer *const serializer"
    for mem in type_desc.members:
        if mem.name.startswith('pad'):
            continue
        type_name = get_cpp_type_name(mem.type_desc)
        if mem.type_desc.type_type == 'union':
            type_name = 'void'
        elif mem.type_desc.type_type == 'struct' and (not mem.type_desc.is_primitive) and (not mem.type_desc.name == 'string'):
            type_name = f"{type_name}Struct"
            
        if mem.is_array:
            type_name = f"Vector<{type_name}>"
        if mem.is_offset_type:
            ret_str += f",\n const SerializeOffset<{type_name}> {mem.name}"
        else:
            ret_str += f",\n const {type_name} {mem.name}"
    ret_str += "){\n"
    
    ret_str += f"SerializeOffset<{type_desc.name}> {type_desc.name.lower()}_offset;\n"
    ret_str += f"serializer->_tail_offset += get_padding_size(serializer->_tail_offset, {type_desc.name.upper()}_ALIGNMENT);\n"
    ret_str += "serializer->make_buffer_adequate();\n"
    ret_str += f"{type_desc.name.lower()}_offset.offset = serializer->_tail_offset;\n\n"
    
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
            type_name = f"Vector<{type_name}>"
            
        if mem.is_offset_type:
            ret_str += f"SerializeOffset<{type_name}> {mem.name};\n"
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
            
            
    
def generate_root_type_serialization_function(types_desc: 
    set[TypeDesc], root_type_name: str) -> str:
    ret_str = ""
    root_type_desc =cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc))
    ret_str += "unsigned char *"
    ret_str += f"finish_serialize_{root_type_desc.name.lower()}"
    ret_str += "(Serializer *const serializer"
    for mem in root_type_desc.members:
        if mem.name.startswith('pad'):
            continue
        type_name = get_cpp_type_name(mem.type_desc)
        if mem.type_desc.type_type == 'union':
            type_name = 'void'
        elif mem.type_desc.type_type == 'struct' and (not mem.type_desc.is_primitive) and (not mem.type_desc.name == 'string'):
            type_name = f"{type_name}Struct"
            
        if mem.is_array:
            type_name = f"Vector<{type_name}>"
        if mem.is_offset_type:
            ret_str += f",\n const SerializeOffset<{type_name}> {mem.name}"
        else:
            ret_str += f",\n const {type_name} {mem.name}"
    ret_str += "){\n"
    
    ret_str += f"uint16_t current_offset = OFFSET_SIZE * 2 + get_padding_size(OFFSET_SIZE * 2, {root_type_desc.name.upper()}_ALIGNMENT);"
    ret_str += '\n\n'
    
    ret_str += generate_struct_serializer_fields(root_type_desc, is_root_type= True, additional_prefix= "", access_prefix = "")
           
    
    ret_str += "\n"
    ret_str += "return serializer->_buffer;\n"
    ret_str += "}"
    
    return ret_str

def generate_serialize_vector_struct(type_desc: TypeDesc) -> str:
    ret_str = ""
    ret_str += f"SerializeOffset<Vector<{type_desc.name}Struct>> "
    ret_str += f"serialize_vector_{type_desc.name.lower()}_struct("
    ret_str += f"Serializer *const serializer, std::vector<{type_desc.name}Struct> data_array){{\n"
    ret_str += f"SerializeOffset<Vector<{type_desc.name}Struct>> data_array_offset;\n"
    ret_str += "uint16_t len = data_array.size();\n"
    ret_str += "serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);\n"
    ret_str += "serializer->make_buffer_adequate();\n"
    ret_str += "data_array_offset.offset = serializer->_tail_offset;\n"
    ret_str += "*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;\n"
    ret_str += "serializer->_tail_offset += OFFSET_SIZE;"
    ret_str += f"serializer->_tail_offset += get_padding_size(serializer->_tail_offset, {type_desc.name.upper()}_ALIGNMENT);"
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

def generate_cpp_code(types_desc: set[TypeDesc], root_type_name: str):
    str_file:str = ""
    
    str_file += get_header_files()
    str_file += '\n\n'
    str_file += get_all_type_declaration(types_desc)
    str_file += '\n\n'
    str_file += get_base_offset_types()
    str_file += '\n\n'
    defined_type: List[str] = []
    str_file += get_all_type_definition(types_desc, root_type_name, defined_type)
    # str_file += get_root_type_definition(types_desc)
    
    str_file += get_base_serializer_class_function()
    str_file += '\n\n'
    str_file += get_all_type_struct_offset_struct_field_struct(types_desc)
    str_file += '\n\n'
    str_file += get_all_types_offset_serialization_function(types_desc)
    str_file += '\n\n'
    str_file += generate_all_types_serialize_vector_struct(types_desc= types_desc)
    str_file += '\n\n'
    str_file += generate_root_type_serialization_function(types_desc, root_type_name)
    return str_file
    


# SerializeOffset<Vector<WeaponField>> serialize_vector_weapon(Serializer *const serializer, std::vector<WeaponField> data_array)
# {
#     SerializeOffset<Vector<WeaponField>> data_array_offset;
#     size_t len = data_array.size();
#     serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);

#     serializer->make_buffer_adequate();
#     data_array_offset.offset = serializer->_tail_offset;

#     *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
#     serializer->_tail_offset += OFFSET_SIZE;
#     serializer->_tail_offset += get_padding_size(serializer->_tail_offset, WEAPON_ALIGNMENT);

#     for (size_t i = 0; i < len; i++)
#     {
#         *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + WEAPON_NAME_OFFSET])) = data_array[i].name.offset - (serializer->_tail_offset + WEAPON_NAME_OFFSET);
#         *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + WEAPON_DAMAGE_OFFSET])) = data_array[i].damage;
#         serializer->_tail_offset += WEAPON_SIZE;
#     }
#     return data_array_offset;
# }