

import json
import struct
from typing import List, Dict
offset_size = 2

def generate_primitive_bytearray(value, type_name: str) -> bytearray:
    if value == None:
        raise ValueError("Don't know what to do yet")
        return bytearray(b'\x00' * type.size)
    elif type_name == 'char':       
        return value.encode(encoding='ascii')[0:1]
    elif type_name == 'int8':
        val = int(value)
        return bytearray(struct.pack('b', val))
    elif type_name == 'uint8':
        val = int(value)
        return bytearray(struct.pack('B', val))
    elif type_name == 'int16':
        val = int(value)
        return bytearray(struct.pack('<h', val))
    elif type_name == 'uint16':
        val = int(value)
        return bytearray(struct.pack('<H', val))
    elif type_name == 'int32':
        val = int(value)
        return bytearray(struct.pack('<i', val))
    elif type_name == 'uint32':
        val = int(value)
        return bytearray(struct.pack('<I', val))
    elif type_name == 'int64':
        val = int(value)
        return bytearray(struct.pack('<q', val))
    elif type_name == 'uint64':
        val = int(value)
        return bytearray(struct.pack('<Q', val))
    elif type_name == 'float32':
        val = float(value)
        return bytearray(struct.pack('<f', val))
    elif type_name == 'float64':
        val = float(value)
        return bytearray(struct.pack('<d', val))
    # elif type_name == 'string':
    #     str_type = 'int16'
    #     if str_type == None:
    #         raise ValueError(f"The raw string type of {str_type} is not allowed.")
    #     item_byte: bytearray = generate_primitive_bytearray(len(value), str_type)
    #     item_byte.extend(value.encode(encoding='ascii'))
    #     item_byte.append(0x00)
    #     return item_byte
    elif type_name == 'offset':
        val = int(value)
        if offset_size == 2:
            return bytearray(struct.pack('<H', val))
        elif offset_size == 4:
            return bytearray(struct.pack('<I', val))
        elif offset_size == 8:
            return bytearray(struct.pack('<Q', val))
    else:
        raise ValueError(f"Unsupported primitive type: {type_name}")