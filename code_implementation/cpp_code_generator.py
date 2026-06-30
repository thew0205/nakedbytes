"""
Top-level C++ code generation entry point for nakedbytes.

This module assembles the complete generated C++ header file by orchestrating
calls to the deserializer and serializer sub-generators. The output is a
self-contained, include-guard-protected `.nbs.h` header that contains:

  - Required `#include` directives and base offset-type definitions.
  - Forward declarations for all resolved types.
  - Type struct definitions (offsets, sizes, alignment macros, accessor methods).
  - A root-buffer accessor helper function.
  - The nakedbytes `Serializer` base class template.
  - Serializer input structs (one per non-primitive type).
  - Inline serialization functions for every type.
  - Vector-of-struct serialization helpers.
  - A strongly-typed root-type serializer class.
"""

from typing import List
from code_implementation.cpp_code_generator_deserializer import get_all_type_declaration, get_all_type_definition, get_base_offset_types, get_header_files, get_root_buffer_accessor_function, get_root_type_definition
from code_implementation.cpp_code_serializer import generate_all_types_serialize_vector_struct, generate_root_type_serialization_class, get_all_type_struct_offset_struct_field_struct, get_all_types_offset_serialization_function, get_base_serializer_class_function
from code_implementation.type_desc_holder import TypeDesc

def generate_cpp_code(types_desc: set[TypeDesc], root_type_name: str, namespace: str|None, file_name: str, offset_size: int, version: int) -> str:
    """
    Generate a complete nakedbytes C++ header file as a string.

    The generated file is wrapped in an include guard derived from `file_name`
    and optionally enclosed in a user-specified namespace. The overall output
    structure is:

    1. Include guard + ``#include`` directives + base offset-type definitions.
    2. [Optional namespace open]
    3. Forward declarations for all types.
    4. Full struct/class definitions with offset macros and accessor methods.
    5. Root-buffer accessor function.
    6. [Optional namespace close]
    7. nakedbytes ``Serializer`` base class (outside namespace).
    8. [Optional namespace re-open]
    9. Serializer input structs (``<Type>Struct``).
    10. Per-type inline serialization functions.
    11. Per-type ``serialize_vector_<type>_struct`` helpers.
    12. Root-type serializer class (``<RootType>Serializer``).
    13. [Optional namespace close] + include-guard end.

    Args:
        types_desc (set[TypeDesc]): The full set of resolved type descriptions
            produced by the schema parser.
        root_type_name (str): The name of the root type. This determines which
            type gets the fixed-offset ``serialize_root()`` method and the
            ``GetRoot<Type>`` accessor function.
        namespace (str | None): An optional C++ namespace to wrap the generated
            type definitions in. Pass ``None`` to omit namespacing.
        file_name (str): The base name of the output file (without extension),
            used to build the include-guard symbol.
        offset_size (int): The size in bytes of the offset type used throughout
            the generated code (e.g. ``2`` for ``uint16_t``).
        version (int): The schema version constant embedded in the generated
            header via the ``VERSION`` macro.

    Returns:
        str: The complete generated C++ header file content.
    """
    str_file:str = ""
    str_file += f"#ifndef __{file_name.upper()}_NAKEDBYTES_GENERATED_H\n"
    str_file += f"#define __{file_name.upper()}_NAKEDBYTES_GENERATED_H\n"
    str_file += get_header_files(offset_size = offset_size, version= version)
    str_file += '\n\n'
    str_file += get_base_offset_types(offset_size = offset_size)
    str_file += '\n\n'
    
    if namespace:
        str_file += f'namespace {namespace} {{\n'
        
    str_file += get_all_type_declaration(types_desc)
    str_file += '\n\n'

    defined_type: List[str] = []
    str_file += get_all_type_definition(types_desc, root_type_name, defined_type, offset_size= offset_size)
    # str_file += get_root_type_definition(types_desc, root_type_name)
    str_file += get_root_buffer_accessor_function(root_name= root_type_name)
    if namespace:
        str_file += f'\n}} // namespace {namespace}\n'
        
    str_file += get_base_serializer_class_function(offset_size= offset_size)
    str_file += '\n\n'
    if namespace:
        str_file += f'namespace {namespace} {{\n'
    str_file += get_all_type_struct_offset_struct_field_struct(types_desc)
    str_file += '\n\n'
    str_file += get_all_types_offset_serialization_function(types_desc, offset_size= offset_size)
    str_file += '\n\n'
    str_file += generate_all_types_serialize_vector_struct(types_desc= types_desc, offset_size= offset_size)
    str_file += '\n\n'
    str_file += generate_root_type_serialization_class(types_desc, root_type_name, offset_size= offset_size)
    if namespace:
        str_file += f'\n}} // namespace {namespace}\n'
    
    str_file += f"#endif //__{file_name.upper()}_NAKEDBYTES_GENERATED_H"
    return str_file
    

