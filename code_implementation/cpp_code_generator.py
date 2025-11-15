

from typing import List
from code_implementation.type_desc_holder import MemberDesc, TypeDesc


def get_header_files() -> str:
    return '''
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define OFFSET_SIZE 2

'''

def get_base_offset_types() -> str:
    return '''
struct StringOffset
{
    unsigned char *data;
    StringOffset(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define STRING_LENGTH_OFFSET 0
    uint16_t length()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *value()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }
};

template <typename T>
struct Union
{
    unsigned char *data;
    Union(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define UNION_TYPE_OFFSET 0
    uint16_t type()
    {
        return *reinterpret_cast<uint16_t *>(&data[UNION_TYPE_OFFSET]);
    }

#define DATA_OFFSET 2
    unsigned char *raw_data()
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) + DATA_OFFSET;

        return (&data[offset]);
    }
    
    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) == 0;
    }
};

template <typename T>
struct Vector
{
    unsigned char *data;

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }
    
    uint16_t size()
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index)
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + OFFSET_SIZE * index;
       

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};
'''

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
    ret_str += f"{mem.type_desc.name} {mem.name}() {{"
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        
    ret_str += f"return *reinterpret_cast<{mem.type_desc.name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2 * OFFSET_SIZE' if is_root_type else ''}]);"
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_primitive_number_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ""
    type_name = convert_to_cpp_primitive_type(mem.type_desc.name)
    ret_str += f"{type_name} {mem.name}() {{"
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        
    ret_str += f"return *reinterpret_cast<{type_name}*>(&data_[{parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''}]);"
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
        
    ret_str += f"}}"
    return ret_str

def generate_struct_string_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'StringOffset {mem.name}(){{'
    
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
        
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += 'return StringOffset(&data_[offset]);'
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
    ret_str += f"}}"
    return ret_str
    
def generate_struct_vector_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    
    if mem.type_desc.is_offset_type:
        if mem.type_desc.type_type == 'union':
            type_name = f'Union<{mem.type_desc.name}>'
        elif mem.type_desc.name == 'string':
            type_name = f'StringOffset'
        elif mem.type_desc.type_type == 'struct_offset':
            type_name = f'{mem.type_desc.name}Offset'
        elif mem.type_desc.type_type == 'class':
            type_name = f'{mem.type_desc.name}Offset'
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
        
            
        
    ret_str += f'Vector<{type_name}> {mem.name}(){{'
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return Vector<{type_name}>(&data_[offset]);'
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
    ret_str += f"}}"
    return ret_str

def generate_struct_union_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'Union<{mem.type_desc.name}> {mem.name}(){{'
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f'const int16_t offset = {parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET - 2;'
    ret_str += f'return Union<{mem.type_desc.name}>(&data_[offset]);'
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
    ret_str += f"}}"
    return ret_str

def generate_struct_class_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = ''
    ret_str += f'{mem.type_desc.name}Offset {mem.name}(){{'
    if parent_type_desc.type_type == 'class':
        ret_str += f'if({parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET < *reinterpret_cast<uint16_t *>(&data_[{parent_type_desc.name.upper()}_MEMBER_SIZE_OFFSET])){{'
    ret_str += f'const int16_t offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
    ret_str += f'return {mem.type_desc.name}Offset(&data_[offset]);'
    if parent_type_desc.type_type == 'class':
        ret_str += f'}}'
    ret_str += f"}}"
    return ret_str

# def generate_struct_class_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
#     ret_str = ''
#     ret_str += f'{mem.type_desc.name}Offset {mem.name}(){{'
#     ret_str += f'const int16_t offset ={parent_type_desc.name.upper()}_{mem.name.upper()}_OFFSET {'+ 2* OFFSET_SIZE' if is_root_type else ''};'
#     ret_str += f'return {mem.type_desc.name}Offset(&data_[offset]);'
#     if parent_type_desc.type_type == 'class':
#         ret_str += f'}}'
#     ret_str += f"}}"
#     return ret_str

def generate_struct_offset_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    if mem.is_array:
        return generate_struct_vector_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type == 'union':
        return generate_struct_union_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.name == 'string':
        return generate_struct_string_member_get_function(mem, parent_type_desc, is_root_type)
    elif mem.type_desc.type_type in ['struct_offset', 'class']:
        
        return generate_struct_class_struct_offset_member_get_function(mem, parent_type_desc, is_root_type)
    
    # elif mem.type_desc.type_type == 'class':
    #     return generate_struct_class_member_get_function(mem, parent_type_desc, is_root_type)
    else:
        raise ValueError(f"Type of {mem.type_desc.name} is not an offset type")
    
def generate_struct_struct_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
    ret_str = f'{mem.type_desc.name} {mem.name}(){{'
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
       

    #     StringOffset id()
    # {

    #     if (SUNSPECPOINTDEF_ID_OFFSET < reinterpret_cast<uint16_t *>(&data_[0]))
    #     {
    #         const int16_t offset = SUNSPECPOINTDEF_ID_OFFSET;
    #         return StringOffset(&data_[offset]);
    #     }
    # }
     
# def generate_class_member_get_function(mem: MemberDesc, parent_type_desc: TypeDesc, is_root_type: bool) -> str:
#     ret_str = ""
#     if mem.is_offset_type:
#         ret_str += generate_class_offset_member_get_function(mem, parent_type_desc, is_root_type)
#     elif mem.type_desc.is_primitive:
#         ret_str += generate_class_primitive_number_member_get_function(mem, parent_type_desc, is_root_type)
#     elif mem.type_desc.type_type == 'enum':
#         ret_str += generate_class_enum_number_member_get_function(mem, parent_type_desc, is_root_type)
#     elif mem.type_desc.type_type == 'struct':
#         ret_str += generate_class_struct_member_get_function(mem, parent_type_desc, is_root_type)
#     return ret_str

def generate_constructor(type_desc: TypeDesc) -> str:
    if type_desc.is_primitive or type_desc.type_type == 'enum':
        raise ValueError("Only struct, struct_offset and class can have constructor")
    ret_str = f"{type_desc.name}(unsigned char * data) : data_(data) {{}}"
    return ret_str
    
def generate_define_offset_macro(type_desc: TypeDesc) -> str:
    ret_str = ""
    for mem in type_desc.members:
        ret_str += f"#define {type_desc.name.upper()}_{mem.name.upper()}_OFFSET {mem.offset}\n"
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
    ret_str += f'{type_desc.name}_to_string({type_desc.name} value){{'
    ret_str += 'switch (value){'
    for e_mem in type_desc.e_members:
        ret_str += f'case {e_mem.name}:'
        ret_str += f'return "{e_mem.name}";'
    
        
    ret_str += 'default: return NULL;'
    ret_str += '}'
    ret_str += f'}}'
    
    return ret_str
        
def generate_struct_offset_struct_class_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
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
            mem_str_type_definition += generate_type_definition(mem.type_desc, False, type_def_generated)
        ret_str += generate_struct_class_member_get_function(mem, type_desc, is_root_type)
        ret_str += '\n\n'
        
    ret_str += f"}};"
    ret_str += '\n\n'
    
    ret_str =  mem_str_type_definition + '\n\n' + ret_str
    ret_str += '\n\n'
    
    if type_desc.type_type in ['struct_offset', 'class']:
        ret_str += generate_type_definition_of_struct_offset_type(type_desc)
    return ret_str


def generate_class_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    ret_str = ''
    ret_str += f"struct {type_desc.name} {{"
    ret_str += '\n\n'
    ret_str += f"unsigned char * data_;"
    ret_str += '\n\n'
    ret_str += generate_constructor(type_desc)
    ret_str += '\n\n'
    ret_str += f"#define {type_desc.name.upper()}_MEMBER_SIZE_OFFSET 0\n"
    ret_str += generate_define_offset_macro(type_desc)
    ret_str += '\n\n'
    
    mem_str_type_definition = ''
    for mem in type_desc.members:
        if mem.name.startswith('pad'):
            continue
        if not mem.type_desc.is_primitive and not mem.type_desc.name in type_def_generated:
            mem_str_type_definition += generate_type_definition(mem.type_desc, False, type_def_generated)
        ret_str += generate_class_member_get_function(mem, type_desc, is_root_type)
        ret_str += '\n\n'
        
    ret_str += f"}};"
    ret_str += '\n\n'
    
    ret_str =  mem_str_type_definition + '\n\n' + ret_str
    ret_str += '\n\n'
    ret_str += generate_type_definition_of_struct_offset_type(type_desc)
    return ret_str

def generate_type_definition(type_desc: TypeDesc, is_root_type: bool, type_def_generated: set[str]) -> str:
    if type_desc.name in type_def_generated:
        return ''
    type_def_generated.add(type_desc.name)
    
    ret_str = ''
    if type_desc.is_primitive:
        raise ValueError(f'Type of {type_desc.name} is a primitive type Type definition cannot to be generated.')
    
    if type_desc.type_type == 'enum':           
        ret_str += generate_enum_type_definition(type_desc=type_desc, is_root_type=is_root_type, type_def_generated=type_def_generated)
    elif type_desc.type_type in ['struct', 'struct_offset', 'class']:
        ret_str += generate_struct_offset_struct_class_type_definition(type_desc=type_desc, is_root_type= is_root_type, type_def_generated= type_def_generated)
    # elif type_desc.type_type == 'class':
    #     ret_str += generate_class_type_definition(type_desc=type_desc, is_root_type= is_root_type, type_def_generated= type_def_generated)
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
    ret_str += f'{type_desc.name} value(){{'
    ret_str += ' const int16_t offset = *reinterpret_cast<int16_t *>(data_);'
    ret_str += f'return {type_desc.name}(&data_[offset]);'
    ret_str += f"}}"
    
    ret_str += f"}};"
    return ret_str

def get_all_type_definition(types_desc: set[TypeDesc], root_type_name: str, defined_type: List[str]) -> str:
    type_def_generated: set[str] = set()
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive:
            continue
        ret_str += generate_type_definition(type_desc, is_root_type= type_desc.name == root_type_name, type_def_generated = type_def_generated)
        
        ret_str += '\n\n'
    return ret_str

def get_all_type_declaration(types_desc: set[TypeDesc]) -> str:
    ret_str = ""
    for type_desc in types_desc:
        if type_desc.is_primitive:
            continue
        if type_desc.type_type == 'enum':
            # ret_str += f"enum {type_desc.name}; \n"
            continue
        else:
            ret_str += f"struct {type_desc.name}; \n"
            if type_desc.is_offset_type:
                ret_str += f"struct {type_desc.name}Offset; \n"
    return ret_str


# def get_root_type_definition(root_type_desc: TypeDesc) -> str:
#     ret_str = f"struct {root_type_desc.name} {{"
#     ret_str += '\n\n'
#     ret_str += f"unsigned char * data_;"
#     ret_str += '\n\n'
#     ret_str += generate_constructor(root_type_desc)
#     ret_str += '\n\n'
#     ret_str += generate_define_offset_macro(root_type_desc)
#     ret_str += '\n\n'
    
#     for mem in root_type_desc.members:
#         if mem.name.startswith('pad'):
#             continue
#         ret_str += generate_struct_member_get_function(mem, root_type_desc)
#         ret_str += '\n\n'
        
#     ret_str += f"}};"
#     return ret_str
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
    
    return str_file
    pass


