

import struct
from typing import Tuple
from code_implementation.type_desc_holder import TypeDesc, get_offset_type_desc_int
from code_implementation.type_utils import get_padding_size

def check_and_increment_bytearray(array: bytearray,new_size: int) -> int:
    """
    Check and increment the byte array size by adding 1kB and return the new size.
    """
    while(len(array) < new_size):
        array.extend(bytearray(1024))
        # old_size += 1024
    return len(array)  

def generate_primitive_number_byte(value: str|int|float|bool, type_desc: TypeDesc) -> bytearray:
    """
Return the byte representation of the primitive number (float, int, float and double)
"""
    if value == None:
        # raise ValueError("Don't know what to do yet")
        return bytearray(b'\x00' * type_desc.size)
    elif type_desc.name == 'bool':
        value_bool: bool =  False
        if(isinstance(value, str)):
            value_bool = value.lower() == 'true'
        elif(isinstance(value, int)):
            value_bool = value != 0
        elif(isinstance(value, bool)):
            value_bool = value
        return bytearray(struct.pack('b', value_bool))
    elif type_desc.name == 'char':  
        return bytearray(str(value).encode(encoding='utf-8')[0:1])
    
    elif type_desc.name in ['int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']:
        base = 10
        
        if(isinstance(value, str)):
            if value.lower().startswith('0x'):
                base = 16
            elif value.lower().startswith('0o'):
                base = 8
            elif value.lower().startswith('0b'):
                base = 2
            else:
                base = 10
                
            value_int: int = int(value, base)
            
        elif(isinstance(value, int)):
            value_int = value
 
        if type_desc.name == 'int8':
            return bytearray(struct.pack('b', value_int))
        elif type_desc.name == 'uint8':
            return bytearray(struct.pack('B', value_int))
        elif type_desc.name == 'int16':
            return bytearray(struct.pack('<h', value_int))
        elif type_desc.name == 'uint16':
            return bytearray(struct.pack('<H', value_int))
        elif type_desc.name == 'int32':
            return bytearray(struct.pack('<i', value_int))
        elif type_desc.name == 'uint32':
            return bytearray(struct.pack('<I', value_int))
        elif type_desc.name == 'int64':
            return bytearray(struct.pack('<q', value_int))
        elif type_desc.name == 'uint64':
            return bytearray(struct.pack('<Q', value_int))
    
    elif type_desc.name in ['float32', 'float64']:
        value_float: float = float(value)
        if type_desc.name == 'float32':
            return bytearray(struct.pack('<f', value_float))
        elif type_desc.name == 'float64':
            value_float = float(value)
            return bytearray(struct.pack('<d', value_float))
    
    raise ValueError(f"Unsupported primitive type: {type_desc.name}")


def generate_enum_byte(model ,offset_size: int, current_type_desc: TypeDesc, types_desc: set[TypeDesc]) -> bytearray:
    """
Generate the byte representation for an enum by check for the enum value in the enum definition and storing it in the underlining int byte size.
"""
    if current_type_desc.type_type != 'enum':
        raise ValueError(f"The type must be of type union instead of {current_type_desc.type_type}")
    model = f"{current_type_desc.name}_{model}" 
    for i, item in enumerate(current_type_desc.e_members):
        if item.name == model:
            val = item.value

            return generate_primitive_number_byte(value= val, type_desc= current_type_desc.basetype, )
    else:
        raise ValueError(f"Enum value {model}'] not found in enum {current_type_desc.e_members}.")
    

def generate_string_byte(model: str, root_array: bytearray,  current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int) ->Tuple[int, int]:
    """
    Generate the byte representation of a string storing the len with the offset size representation and copying the string byte in the bytearray provided.
    """
    if current_type_desc.name != 'string':
        raise ValueError(f"The type must be of type string instead of {current_type_desc.type_type}")
    current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
    tail_offset = current_offset + offset_size + len(model) + 1
    
    check_and_increment_bytearray(root_array, tail_offset)

    root_array[current_offset: current_offset + offset_size] =  generate_primitive_number_byte(len(model), get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc))
    root_array[current_offset + offset_size : current_offset + offset_size + len(model)] = bytearray(model.encode(encoding='utf-8'))
    root_array[current_offset + offset_size + len(model) : current_offset + offset_size + len(model) +1 ] = bytearray([0x00])
    return current_offset, tail_offset

"""
Generate the byte representation of a blob storing the len with the offset size representation and copying the bytes in the bytearray provided.
"""
def generate_blob_type(model: str, root_array: bytearray, array_size: int, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int) ->Tuple[int, int]:
    pass