from typing import List
from code_implementation.cpp_code_generator_deserializer import get_all_type_declaration, get_all_type_definition, get_base_offset_types, get_header_files, get_root_type_definition
from code_implementation.cpp_code_serializer import generate_all_types_serialize_vector_struct, generate_root_type_serialization_function, get_all_type_struct_offset_struct_field_struct, get_all_types_offset_serialization_function, get_base_serializer_class_function
from code_implementation.type_desc_holder import TypeDesc


def generate_cpp_code(types_desc: set[TypeDesc], root_type_name: str, namespace: str) -> str:
    str_file:str = ""
    
    str_file += get_header_files()
    str_file += '\n\n'
    if namespace:
        str_file += f'namespace {namespace} {{\n'
    str_file += get_all_type_declaration(types_desc)
    str_file += '\n\n'
    str_file += get_base_offset_types()
    str_file += '\n\n'
    defined_type: List[str] = []
    str_file += get_all_type_definition(types_desc, root_type_name, defined_type)
    str_file += get_root_type_definition(types_desc, root_type_name)
    
    str_file += get_base_serializer_class_function()
    str_file += '\n\n'
    str_file += get_all_type_struct_offset_struct_field_struct(types_desc)
    str_file += '\n\n'
    str_file += get_all_types_offset_serialization_function(types_desc)
    str_file += '\n\n'
    str_file += generate_all_types_serialize_vector_struct(types_desc= types_desc)
    str_file += '\n\n'
    str_file += generate_root_type_serialization_function(types_desc, root_type_name)
    
    if namespace:
        str_file += f'\n}} // namespace {namespace}\n'
    return str_file
    

