from typing import List, cast
from code_implementation.cpp_code_generator_utils import convert_to_cpp_primitive_type, generate_define_offset_macro, get_cpp_default_value, get_cpp_type_name, get_signed_offset_type, get_unsigned_offset_type
from code_implementation.cpp_code_serializer import generate_all_types_serialize_vector_struct, get_all_type_struct_offset_struct_field_struct, get_all_types_offset_serialization_function, get_base_serializer_class_function
from code_implementation.type_desc_holder import MemberDesc, TypeDesc, get_type_desc_from_types_desc

def get_header_files(offset_size: int, version: int) -> str:
    """Generated the header file and defines needed.
    Defines the offset size and version"""
    return f'''
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <type_traits>
#include <vector>

#define OFFSET_SIZE ({offset_size})
#define VERSION ({version})

#if defined(__GNUC__) || defined(__clang__)
#define NAKEDBYTES_INLINE inline
#else
#define NAKEDBYTES_INLINE inline
#endif

#if defined(__GNUC__) || defined(__clang__)
#define NAKEDBYTES_FORCE_INLINE inline __attribute__((always_inline))
#else
#define NAKEDBYTES_FORCE_INLINE inline
#endif
'''

def get_base_offset_types(offset_size: int) -> str:
    return f'''
namespace nakedbytes{{
NAKEDBYTES_FORCE_INLINE {get_unsigned_offset_type(offset_size)} get_padding_size({get_unsigned_offset_type(offset_size)} offset, uint16_t alignment)
{{
    return static_cast<{get_unsigned_offset_type(offset_size)}>((alignment - (offset % alignment)) % alignment);
}}

struct String
{{
    static constexpr {get_unsigned_offset_type(offset_size)} nakedbytes_sizeof = {offset_size};
    
#define STRING_LENGTH_OFFSET {offset_size * 0}
    NAKEDBYTES_FORCE_INLINE {get_unsigned_offset_type(offset_size)} length() const
    {{
        const {get_signed_offset_type(offset_size)} offset = STRING_LENGTH_OFFSET;
        return *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[offset]);
    }}

#define STRING_VALUE_OFFSET {offset_size * 1}
    NAKEDBYTES_FORCE_INLINE const char *c_str() const
    {{
        const {get_signed_offset_type(offset_size)} offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data_[offset]);
    }}
    
private:
    
    unsigned char data_[1];

    String() = delete;
    String (const String &other) = delete;
    String &operator=(const String &other) = delete;
    
}};

template<typename T, typename Enable = void>
struct Offset
{{
    static constexpr {get_unsigned_offset_type(offset_size)} nakedbytes_sizeof = {offset_size};

    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {{
        return *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]) == 0;
    }}

    NAKEDBYTES_FORCE_INLINE const T* value_ptr() const
    {{
        const {get_signed_offset_type(offset_size)} offset = *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]);
        return reinterpret_cast<const T*>(&data_[offset]);
    }}
    
    NAKEDBYTES_FORCE_INLINE const T& value() const
    {{
        const {get_signed_offset_type(offset_size)} offset = *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }}
    
private:

    unsigned char data_[1];

    Offset() = delete;
    Offset (const Offset &other) = delete;
    Offset &operator=(const Offset &other) = delete;
}};

template<typename T>
struct Offset<T, typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value)>::type>
{{
    static constexpr {get_unsigned_offset_type(offset_size)} nakedbytes_sizeof = sizeof(T);
    
    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {{
        return *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]) == 0;
    }}

    NAKEDBYTES_FORCE_INLINE const T* value_ptr() const
    {{
        const {get_signed_offset_type(offset_size)} offset = *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]);
        return reinterpret_cast<const T*>(&data_[offset]);
    }}
    
    NAKEDBYTES_FORCE_INLINE const T& value() const
    {{
        const {get_signed_offset_type(offset_size)} offset = *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }}
    
private:

    unsigned char data_[1];

    Offset() = delete;
    Offset (const Offset &other) = delete;
    Offset &operator=(const Offset &other) = delete;
}};

template<typename T> struct is_Offset_Type : std::false_type {{}};
template<typename T>
struct is_Offset_Type<Offset<T>> : std::true_type {{}};


template<typename T, typename Enable = void>
struct Vector
{{

static constexpr {get_unsigned_offset_type(offset_size)} nakedbytes_sizeof = {offset_size};

    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {{
        return *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]) == 0;
    }}
    
    NAKEDBYTES_FORCE_INLINE {get_unsigned_offset_type(offset_size)} size() const
    {{
        const {get_signed_offset_type(offset_size)} offset =  *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]);
        return *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[offset]);
    }}

    NAKEDBYTES_FORCE_INLINE const T& get({get_unsigned_offset_type(offset_size)} index) const
    {{
        const {get_signed_offset_type(offset_size)} offset =  static_cast<{get_signed_offset_type(offset_size)}>(*reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0])) + static_cast<{get_signed_offset_type(offset_size)}>(OFFSET_SIZE) + static_cast<{get_signed_offset_type(offset_size)}>(T::nakedbytes_sizeof) * static_cast<{get_signed_offset_type(offset_size)}>(index);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }}
    
    NAKEDBYTES_FORCE_INLINE const T& operator[]({get_unsigned_offset_type(offset_size)} index) const {{
        const {get_signed_offset_type(offset_size)} offset =  static_cast<{get_signed_offset_type(offset_size)}>(*reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]) + OFFSET_SIZE + T::nakedbytes_sizeof * index);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }}

    
private:

    unsigned char data_[1];

    Vector() = delete;
    Vector (const Vector &other) = delete;
    Vector &operator=(const Vector &other) = delete;
}};

template<typename T>
struct Vector<T, typename std::enable_if<(std::is_floating_point<T>::value || std::is_integral<T>::value)>::type>
{{

static constexpr {get_unsigned_offset_type(offset_size)} nakedbytes_sizeof = {offset_size};

    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {{
        return *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]) == 0;
    }}
    
    NAKEDBYTES_FORCE_INLINE {get_unsigned_offset_type(offset_size)} size() const
    {{
        const {get_signed_offset_type(offset_size)} offset =  *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0]);
        return *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[offset]);
    }}

    NAKEDBYTES_FORCE_INLINE const T& get({get_unsigned_offset_type(offset_size)} index) const
    {{
        const {get_signed_offset_type(offset_size)} offset =  static_cast<{get_signed_offset_type(offset_size)}>(*reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0])) + static_cast<{get_signed_offset_type(offset_size)}>(OFFSET_SIZE) + static_cast<{get_signed_offset_type(offset_size)}>(OFFSET_SIZE) * static_cast<{get_signed_offset_type(offset_size)}>(index);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }}
    
    NAKEDBYTES_FORCE_INLINE const T& operator[]({get_unsigned_offset_type(offset_size)} index) const {{
        const {get_signed_offset_type(offset_size)} offset =  static_cast<{get_signed_offset_type(offset_size)}>(*reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[0])) + static_cast<{get_signed_offset_type(offset_size)}>(OFFSET_SIZE) + static_cast<{get_signed_offset_type(offset_size)}>(OFFSET_SIZE) * static_cast<{get_signed_offset_type(offset_size)}>(index);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }}


private:

    unsigned char data_[1];

    Vector() = delete;
    Vector (const Vector &other) = delete;
    Vector &operator=(const Vector &other) = delete;
}};
}}; //namespace nakedbytes
'''








def generate_struct_enum_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    is_class_type = parent_type_desc.type_type == 'class'
    ret_str = ""
    ret_str += f"{"NAKEDBYTES_INLINE" if is_class_type else "NAKEDBYTES_FORCE_INLINE"} {mem.type_desc.name} {mem.name}() const {{"
    ret_str += '\n'
    if is_class_type:
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}])){{'
        ret_str += '\n'
        
    ret_str += f"return *reinterpret_cast<const {mem.type_desc.name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2 * OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'}}'
        ret_str += '\n'
        
    ret_str += f"}}"
    return ret_str


    
def generate_struct_primitive_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    is_class_type = parent_type_desc.type_type == 'class'
    ret_str = ""
    type_name = convert_to_cpp_primitive_type(mem.type_desc.name)
    ret_str += f"{"NAKEDBYTES_INLINE" if is_class_type else "NAKEDBYTES_FORCE_INLINE"} {type_name} {mem.name}() const {{"
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}])){{'
        ret_str += '\n'
        
    ret_str += f"return *reinterpret_cast<const {type_name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'}}'
        ret_str += '\n'
        ret_str += f'return {get_cpp_default_value(mem.type_desc, mem.default_value)};\n'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_string_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    is_class_type = parent_type_desc.type_type == 'class'
    ret_str = ''
    ret_str += f'{"NAKEDBYTES_INLINE" if is_class_type else "NAKEDBYTES_FORCE_INLINE"} const ::nakedbytes::Offset<::nakedbytes::String>* {mem.name}() const {{'
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}])){{'
        ret_str += '\n'
        
        
    ret_str += f'const {get_signed_offset_type(offset_size)} offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += '\n'
    
    ret_str += 'return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String>*>(&data_[offset]);'
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'}}'
        ret_str += '\n'
        ret_str += 'return nullptr;\n'
    ret_str += f"}}"
    return ret_str
    
def generate_struct_vector_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    is_class_type = parent_type_desc.type_type == 'class'
    ret_str = ''
    
    if mem.type_desc.is_offset_type:
        if mem.type_desc.type_type == 'union':
            type_name = f'{mem.type_desc.name}'
        elif mem.type_desc.name == 'string':
            type_name = f'::nakedbytes::Offset<nakedbytes::String>'
        elif mem.type_desc.type_type in ['struct_offset', 'class']:
            type_name = f'::nakedbytes::Offset<{mem.type_desc.name}>'
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
        
            
        
    ret_str += f'{"NAKEDBYTES_INLINE" if is_class_type else "NAKEDBYTES_FORCE_INLINE"} const ::nakedbytes::Vector<{type_name}>* {mem.name}() const {{'
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}])){{'
        ret_str += '\n'
        
    ret_str += f'const {get_signed_offset_type(offset_size)} offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += '\n'
    
    ret_str += f'return reinterpret_cast<const ::nakedbytes::Vector<{type_name}>*>(&data_[offset]);'
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'}}'
        ret_str += '\n'
        ret_str += 'return nullptr;\n'
                
    ret_str += f"}}"
    return ret_str

def generate_struct_union_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    is_class_type = parent_type_desc.type_type == 'class'
    ret_str = ''
    ret_str += f'{"NAKEDBYTES_INLINE" if is_class_type else "NAKEDBYTES_FORCE_INLINE"} const {mem.type_desc.name}* {mem.name}() const {{'
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}])){{'
        ret_str += '\n'
        
    ret_str += f'const {get_signed_offset_type(offset_size)} offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_TYPE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += '\n'
    
    ret_str += f'return reinterpret_cast<const {mem.type_desc.name}*>(&data_[offset]);'
    ret_str += '\n'
    
    if is_class_type:
        ret_str += f'}}'
        ret_str += '\n'
        ret_str += 'return nullptr;\n'
                
    ret_str += f"}}"
    return ret_str

def generate_struct_class_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    is_class_type = parent_type_desc.type_type == 'class'
    ret_str = ''
    ret_str += f'{"NAKEDBYTES_INLINE" if is_class_type else "NAKEDBYTES_FORCE_INLINE"} const ::nakedbytes::Offset<{mem.type_desc.name}>* {mem.name}() const {{'
    if is_class_type:
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}])){{'
    ret_str += f'const {get_signed_offset_type(offset_size)} offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return reinterpret_cast<const ::nakedbytes::Offset<{mem.type_desc.name}>*>(&data_[offset]);'
    if is_class_type:
        ret_str += f'}}\n'
        ret_str += 'return nullptr;\n'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    if mem.is_array:
        return generate_struct_vector_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.type_type == 'union':
        return generate_struct_union_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.name == 'string':
        return generate_struct_string_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.type_type in ['struct_offset', 'class']: 
        return generate_struct_class_struct_offset_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    else:
        raise ValueError(f"Type of {mem.type_desc.name} is not an offset type")
    
def generate_struct_class_struct_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    is_class_type = parent_type_desc.type_type == 'class'
    ret_str = f'{"NAKEDBYTES_INLINE" if is_class_type else "NAKEDBYTES_FORCE_INLINE"} const {mem.type_desc.name}& {mem.name}() const {{'
    if is_class_type:
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<const {get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}])){{'
        ret_str += '\n'
        
    ret_str += f'return *reinterpret_cast<const {mem.type_desc.name} *>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}]);\n'
    if is_class_type:
        ret_str += f'}}'
        ret_str += '\n'
    ret_str += f"}}"
    return ret_str
       
def generate_struct_class_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    ret_str = ""
    if mem.is_offset_type:
        ret_str += generate_struct_offset_member_get_function(mem, parent_type_desc, is_root_type, offset_size = offset_size)
    elif mem.type_desc.is_primitive:
        ret_str += generate_struct_primitive_number_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.type_type == 'enum':
        ret_str += generate_struct_enum_number_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.type_type == 'struct':
        ret_str += generate_struct_class_struct_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    return ret_str


def generate_class_enum_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    ret_str = ""
    ret_str += f"{mem.type_desc.name} {mem.name}() {{"
    
    ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f"return *reinterpret_cast<{mem.type_desc.name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2 * OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += f'}}'
   
    ret_str += f"}}"
    return ret_str

def generate_class_primitive_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    ret_str = ""
    type_name = convert_to_cpp_primitive_type(mem.type_desc.name)
    
    ret_str += f"{type_name} {mem.name}() {{"
    
    ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<{get_unsigned_offset_type(offset_size)} *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f"return *reinterpret_cast<{type_name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2 * OFFSET_SIZE' if is_root_type else ''}]);"
    ret_str += f'}}'
   
    ret_str += f"}}"
    
    return ret_str

def generate_class_string_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    ret_str = ''
    ret_str += f'StringOffset {mem.name}(){{'
    ret_str += f'const {get_signed_offset_type(offset_size)} offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += 'return StringOffset(&data_[offset]);'
    ret_str += f"}}"
    return ret_str
    
def generate_class_vector_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
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
    ret_str += f'const {get_signed_offset_type(offset_size)} offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return Vector<{type_name}>(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_union_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    ret_str = ''
    ret_str += f'Union<{mem.type_desc.name}> {mem.name}(){{'
    ret_str += f'const {get_signed_offset_type(offset_size)} offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET - 2;'
    ret_str += f'return Union<{mem.type_desc.name}>(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    ret_str = ''
    ret_str += f'{mem.type_desc.name}Offset {mem.name}(){{'
    ret_str += f'const {get_signed_offset_type(offset_size)} offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return {mem.type_desc.name}Offset(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_class_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    ret_str = ''
    ret_str += f'{mem.type_desc.name} {mem.name}(){{'
    ret_str += f'const {get_signed_offset_type(offset_size)} offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return {mem.type_desc.name}Offset(&data_[offset]);'
    ret_str += f"}}"
    return ret_str

def generate_class_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool, offset_size: int) -> str:
    if mem.is_array:
        return generate_class_vector_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.type_type == 'union':
        return generate_class_union_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.name == 'string':
        return generate_class_string_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    elif mem.type_desc.type_type == 'struct_offset':
        
        return generate_class_struct_offset_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    
    elif mem.type_desc.type_type == 'class':
        return generate_class_class_member_get_function(mem, parent_type_desc, is_root_type, offset_size= offset_size)
    else:
        raise ValueError(f"Type of {mem.type_desc.name} is not an offset type")
    
def generate_class_struct_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = f'{mem.type_desc.name} {mem.name}(){{'
    ret_str += f'return {mem.type_desc.name}(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}]);'
    ret_str += f"}}"
    return ret_str
       



def generate_constructor(type_desc: TypeDesc, is_root_type: bool) -> str:
    if type_desc.is_primitive or type_desc.type_type == 'enum':
        raise ValueError("Only struct, struct_offset and class can have constructor")
    ret_str = "private:\n"
    ret_str += f"{type_desc.name}{"Root" if is_root_type else ""}() =delete;\n"
    ret_str += f"{type_desc.name}{"Root" if is_root_type else ""}(const {type_desc.name}{"Root" if is_root_type else ""} &) =delete;\n"
    ret_str += f"{type_desc.name}{"Root" if is_root_type else ""}& operator=(const {type_desc.name}{"Root" if is_root_type else ""} &) =delete;\n"
    ret_str += f"unsigned char data_[1];"
    ret_str += '\n\n'
    return ret_str
    


def generate_enum_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    """Generate C++ enum type definition from TypeDesc."""
    ret_str = ''
    ret_str += f'enum {type_desc.name} : {convert_to_cpp_primitive_type(type_desc.basetype.name)} {{'
    ret_str += '\n\n'
    
    for e_mem in type_desc.e_members:
        ret_str += f'{e_mem.name},'
        ret_str += '\n'
        
    ret_str += f'}};'
    
    ret_str += '\n\n'
    
    ret_str += 'inline const char * '
    ret_str += f'{type_desc.name}_to_string({type_desc.name} value){{\n'
    ret_str += 'switch (value){\n'
    
    for e_mem in type_desc.e_members:
        ret_str += f'case {e_mem.name}:\n'
        ret_str += f'return "{e_mem.name}";\n'
    
        
    ret_str += 'default:\nreturn NULL;\n'
    ret_str += '}\n'
    ret_str += f'}}\n'
    
    return ret_str


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




def generate_union_type_access_offset_type_definition(type_desc: TypeDesc, parent_type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    type_name = get_cpp_type_name(type_desc)
        
        # raise ValueError(f"Type of {type_desc.name} is not an offset type")
        
    # if type_desc.is_offset_type:
    #     type_name = f'Offset<{type_name}>'
    ret_str = ''
    ret_str += f'const ::nakedbytes::Offset<{type_name}>* data_as_{type_desc.name}() const {{\n'
    ret_str += f'return type() == {parent_type_desc.name}_enum_{type_desc.name} ? reinterpret_cast<const ::nakedbytes::Offset<{type_name}>*>(&data_[{parent_type_desc.name.upper()}_DATA_OFFSET]) : nullptr;\n'
    ret_str += f'}}'
    
    return ret_str
    
def generate_union_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str], types_desc: set[TypeDesc], offset_size: int) -> str:
    
    ret_str = ''
    ret_str += f'struct {type_desc.name}{{'
    ret_str += '\n\n'
   
    ret_str += f'#define {type_desc.name.upper()}_TYPE_OFFSET {offset_size * 0}\n'
    ret_str += f'#define {type_desc.name.upper()}_DATA_OFFSET {offset_size * 1}\n'
    ret_str += f"#define {type_desc.name.upper()}_ALIGNMENT {type_desc.alignment}\n"
    ret_str += f"#define {type_desc.name.upper()}_SIZE {type_desc.size}\n"
    ret_str += '\n\n'
    

    
    ret_str += 'bool is_null() const {\n'
    ret_str += f'return (type() == 0) or (*reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[{type_desc.name.upper()}_DATA_OFFSET]) == 0);\n'
    ret_str += '}'
    ret_str += '\n\n'
    
    ret_str += 'const unsigned char *raw_data() const {'
    ret_str += f'const {get_signed_offset_type(offset_size)} offset = *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(&data_[{type_desc.name.upper()}_DATA_OFFSET]) + {type_desc.name.upper()}_DATA_OFFSET;\n'
    ret_str += f'return reinterpret_cast<const unsigned char *>(&data_[offset]);\n'
    ret_str += '}\n'
    
    mem_str_type_definition = ''
    if not f'{type_desc.name}_enum' in type_def_generated:
            mem_str_type_definition += generate_type_definition(type_desc = cast(TypeDesc, get_type_desc_from_types_desc(f'{type_desc.name}_enum' , types_desc)),is_root_type= False, type_def_generated= type_def_generated, types_desc= types_desc, offset_size= offset_size)
        
    
    ret_str += f'{type_desc.name}_enum type() const {{\n'
    ret_str += f'return *reinterpret_cast<const {type_desc.name}_enum *>(&data_[{type_desc.name.upper()}_TYPE_OFFSET]);\n'
    ret_str += f'}}'
    ret_str += '\n\n'
    
    for u_type_desc in type_desc.u_members:
        if not u_type_desc.is_primitive and not u_type_desc.name in type_def_generated:
            mem_str_type_definition += generate_type_definition(type_desc = u_type_desc, is_root_type =False, type_def_generated= type_def_generated, types_desc= types_desc, offset_size= offset_size)
        ret_str += generate_union_type_access_offset_type_definition(u_type_desc, type_desc, is_root_type,type_def_generated)
                   
        ret_str += '\n\n'
    
    ret_str += generate_constructor(type_desc, is_root_type)
    ret_str += '\n\n'
    ret_str += f'}};'
    
    ret_str =  mem_str_type_definition + '\n\n' + ret_str
    ret_str += '\n\n'
    

    
    return ret_str
        
def generate_struct_offset_struct_class_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str], types_desc: set[TypeDesc], offset_size: int) -> str:
    is_class_type = type_desc.type_type == 'class'
    ret_str = ''
    ret_str += f"struct {type_desc.name}{"Root" if is_root_type else ""}  {{"
 
    ret_str += '\n\n'
    if is_class_type:
        ret_str += f"#define {type_desc.name.upper()}_MEMBER_SIZE_OFFSET 0\n"
    ret_str += generate_define_offset_macro(type_desc)
    ret_str += '\n\n'
    
    mem_str_type_definition = ''
    for mem in type_desc.members:
        if mem.name.startswith('pad'):
            continue
        if not is_root_type and (not mem.type_desc.is_primitive and not mem.type_desc.name in type_def_generated):
            mem_str_type_definition += generate_type_definition(type_desc = mem.type_desc, is_root_type= False, type_def_generated= type_def_generated, types_desc= types_desc, offset_size= offset_size)
        ret_str += generate_struct_class_member_get_function(mem, type_desc, is_root_type, offset_size= offset_size)
        ret_str += '\n\n'
    
    ret_str += f"static constexpr {get_unsigned_offset_type(offset_size)} nakedbytes_sizeof = {type_desc.size};\n\n"
   
    ret_str += generate_constructor(type_desc=type_desc, is_root_type = is_root_type)
    
    ret_str += f"}};"
    ret_str += '\n\n'
    
    ret_str =  mem_str_type_definition + '\n\n' + ret_str
    ret_str += '\n\n'
    
    return ret_str



def generate_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str], types_desc: set[TypeDesc], offset_size: int) -> str:
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
        ret_str += generate_union_type_definition(type_desc=type_desc, is_root_type=is_root_type, type_def_generated=type_def_generated, types_desc= types_desc, offset_size= offset_size)
    elif type_desc.type_type in ['struct', 'struct_offset', 'class']:
        ret_str += generate_struct_offset_struct_class_type_definition(type_desc=type_desc, is_root_type= is_root_type, type_def_generated= type_def_generated, types_desc= types_desc, offset_size= offset_size)
    return ret_str


def get_root_type_definition(types_desc: set[TypeDesc], root_type_name: str, offset_size: int) -> str:
    
    ret_str = ""
    root_type_desc =cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc))
    if not root_type_desc.type_type in ['struct', 'struct_offset', 'class']:
        raise ValueError(f"Only a structable type can be a root type, {root_type_desc.name} is a {root_type_desc.type_type} type")
    
    return generate_type_definition(root_type_desc, is_root_type= True, type_def_generated = set(), types_desc= types_desc, offset_size= offset_size)
    

def generate_type_definition_of_struct_offset_type(type_desc: TypeDesc, offset_size: int) -> str:
    ret_str = f"struct {type_desc.name}Offset {{"
    ret_str += '\n\n'
    ret_str += f"unsigned char * data_;"
    ret_str += '\n\n'
    ret_str += f"{type_desc.name}Offset (unsigned char * data) : data_(data) {{}}"
    ret_str += '\n\n'
    ret_str += f'''
     bool is_null()
    {{
        return *reinterpret_cast<const {get_signed_offset_type(offset_size)} *>(data_) == 0;
    }}
    '''
    ret_str += '\n\n'
    ret_str += f'{type_desc.name} value(){{\n'
    ret_str += ' const {get_signed_offset_type(offset_size)} offset = *reinterpret_cast<{get_signed_offset_type(offset_size)} *>(data_);\n'
    ret_str += f'return {type_desc.name}(&data_[offset]);\n'
    ret_str += f"}}\n"
    
    ret_str += f"}};"
    return ret_str

def get_all_type_definition(types_desc: set[TypeDesc], root_type_name: str, defined_type: List[str], offset_size: int) -> str:
    type_def_generated: set[str] = set()
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive:
            continue
        ret_str += generate_type_definition(type_desc, is_root_type= False, type_def_generated = type_def_generated, types_desc= types_desc, offset_size= offset_size)
        
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

            

def get_root_buffer_accessor_function(root_name: str) -> str:
    """
    Generate the function to access the start of the root type in the generated buffer by jumping over the length and version and enforcing the alignment.
    """
    ret_str = f"""
        const {root_name} *GetRoot{root_name}(const unsigned char *const buffer)
    {{
        return reinterpret_cast<const {root_name} *>(&buffer[2 * OFFSET_SIZE + ::nakedbytes::get_padding_size((2 * OFFSET_SIZE), {root_name.upper()}_ALIGNMENT)]);
    }}
    """
    return ret_str
