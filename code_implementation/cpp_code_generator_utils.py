from code_implementation.type_desc_holder import TypeDesc


def convert_to_cpp_primitive_type(type_name: str) -> str:
    """
    Convert a primitive type name to its corresponding C++ type name.
    """
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
    

def is_structable_type(type_desc: TypeDesc) -> bool:
    """
    Check if the type description represents a struct, struct_offset, or class type."""
    return type_desc.type_type in ['struct', 'struct_offset', 'class']


def generate_define_offset_macro(type_desc: TypeDesc) -> str:
    """
    Generate C++ macros for the offsets, alignment, and size of the given type description."""
    ret_str = ""
    for mem in type_desc.members:
        ret_str += f"#define {type_desc.name.upper()}_{mem.name.upper()}_OFFSET {mem.offset}\n"
    ret_str += f"#define {type_desc.name.upper()}_ALIGNMENT {type_desc.alignment}\n"
    ret_str += f"#define {type_desc.name.upper()}_SIZE {type_desc.size}\n"
    return ret_str