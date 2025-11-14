
import struct
from typing import Dict, List, Tuple, cast
from code_implementation.type_desc_holder import TypeDesc, get_offset_type_desc_int, get_type_desc_from_types_desc
from code_implementation.type_utils import get_padding_size


def generate_primitive_bytearray_number(value, type_desc: TypeDesc, offset_size: int, types_desc: set[TypeDesc]) -> bytearray:
    if value == None:
        # raise ValueError("Don't know what to do yet")
        return bytearray(b'\x00' * type_desc.size)
    elif type_desc.name == 'char':       
        return value.encode(encoding='ascii')[0:1]
    elif type_desc.name == 'int8':
        val = int(value)
        return bytearray(struct.pack('b', val))
    elif type_desc.name == 'uint8':
        val = int(value)
        return bytearray(struct.pack('B', val))
    elif type_desc.name == 'int16':
        val = int(value)
        return bytearray(struct.pack('<h', val))
    elif type_desc.name == 'uint16':
        val = int(value)
        return bytearray(struct.pack('<H', val))
    elif type_desc.name == 'int32':
        val = int(value)
        return bytearray(struct.pack('<i', val))
    elif type_desc.name == 'uint32':
        val = int(value)
        return bytearray(struct.pack('<I', val))
    elif type_desc.name == 'int64':
        val = int(value)
        return bytearray(struct.pack('<q', val))
    elif type_desc.name == 'uint64':
        val = int(value)
        return bytearray(struct.pack('<Q', val))
    elif type_desc.name == 'float32':
        val = float(value)
        return bytearray(struct.pack('<f', val))
    elif type_desc.name == 'float64':
        val = float(value)
        return bytearray(struct.pack('<d', val))
    else:
        raise ValueError(f"Unsupported primitive type: {type_desc.name}")

def generate_enum_type(model ,offset_size: int, current_type_desc: TypeDesc, types_desc: set[TypeDesc]) -> bytearray:
    if current_type_desc.type_type != 'enum':
        raise ValueError(f"The type must be of type union instead of {current_type_desc.type_type}")
           
    for i, item in enumerate(current_type_desc.e_members):
        if item.name == model:
            val = i
            return generate_primitive_bytearray_number(value= val, type_desc= current_type_desc.basetype, types_desc= types_desc, offset_size= offset_size)
    else:
        raise ValueError(f"Enum value {model}'] not found in enum {current_type_desc.e_members}.")

def generate_vector_type(model: List, root_array: bytearray, array_size: int, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int) ->Tuple[int, int]:
    item_count =  len(model)
    current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
    
    if current_type_desc.is_offset_type:
        
        tail_offset = current_offset + offset_size + item_count * offset_size
        while(array_size < tail_offset):
            root_array.extend(bytearray(1024))
            array_size += 1024
        root_array[current_offset: current_offset + offset_size] = generate_primitive_bytearray_number(item_count, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  offset_size=offset_size, types_desc= types_desc)
        
        for i, item in enumerate(model):
            item_offset = current_offset + offset_size + offset_size * i
            real_item_offset, tail_offset = generate_offset_type(model=item, root_array=root_array, current_type_desc=current_type_desc, types_desc= types_desc, current_offset= tail_offset, offset_size=offset_size, array_size= array_size, is_array= False, true_union_type= None)
            value = 0
            if real_item_offset != None:
                value = real_item_offset - item_offset
            root_array[item_offset: item_offset + offset_size] = generate_primitive_bytearray_number(value, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  offset_size=offset_size, types_desc= types_desc)
    elif current_type_desc.is_primitive:
        tail_offset = current_offset + offset_size + current_type_desc.size * item_count
        while(array_size < tail_offset):
            root_array.extend(bytearray(1024))
            array_size += 1024
        root_array[current_offset: current_offset + offset_size] = generate_primitive_bytearray_number(item_count, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  offset_size=offset_size, types_desc= types_desc)
        for i, item in enumerate(model):
            item_offset = current_offset + current_type_desc.size * i
            root_array[item_offset : item_offset+ current_type_desc.size] = generate_primitive_bytearray_number(value= item, type_desc= current_type_desc, types_desc= types_desc, offset_size=offset_size)
    elif current_type_desc.type_type == 'enum':
        tail_offset = current_offset + offset_size + current_type_desc.size * item_count
        while(array_size < tail_offset):
            root_array.extend(bytearray(1024))
            array_size += 1024
        root_array[current_offset: current_offset + offset_size] = generate_primitive_bytearray_number(item_count, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  offset_size=offset_size, types_desc= types_desc)
        for i, item in enumerate(model):
            item_offset = current_offset + current_type_desc.size * i
            root_array[item_offset : item_offset+ current_type_desc.size] = generate_enum_type(model= item, types_desc= types_desc, offset_size=offset_size, current_type_desc=current_type_desc)
    elif current_type_desc.type_type == 'struct':
        tail_offset = current_offset + offset_size + current_type_desc.size * item_count
        while(array_size < tail_offset):
            root_array.extend(bytearray(1024))
            array_size += 1024
        root_array[current_offset: current_offset + offset_size] = generate_primitive_bytearray_number(item_count, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  offset_size=offset_size, types_desc= types_desc)
        for i, item in enumerate(model):
            item_offset = current_offset + current_type_desc.size * i
            tail_offset = generate_struct_type(model= item, root_array= root_array, array_size= array_size, current_type_desc= current_type_desc, types_desc= types_desc, current_offset= item_offset, tail_offset= tail_offset, offset_size=offset_size)
    else: 
        raise ValueError(f"Type of {current_type_desc.name} is unknown")
            
        
        
    return current_offset, tail_offset

def generate_union_type(model, root_array: bytearray, array_size: int, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int, true_union_type: str) ->Tuple[int, int]:
    if current_type_desc.type_type != 'union':
        raise ValueError(f"The type must be of type union instead of {current_type_desc.type_type}")
    true_union_type_desc = cast(TypeDesc, get_type_desc_from_types_desc(true_union_type, types_desc))
    current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
    tail_offset = current_offset + true_union_type_desc.size 
    while(array_size < tail_offset):
        root_array.extend(bytearray(1024))
        array_size += 1024
    if true_union_type_desc.is_offset_type:
        real_item_offset, tail_offset = generate_offset_type(model=model, root_array=root_array, current_type_desc=true_union_type_desc, types_desc= types_desc, current_offset= tail_offset, offset_size=offset_size, array_size= array_size, is_array= False, true_union_type= None)
        value = 0
        if real_item_offset != None:
            value = real_item_offset - current_offset
        root_array[current_offset: current_offset + offset_size] = generate_primitive_bytearray_number(value, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  offset_size=offset_size, types_desc= types_desc)
    elif true_union_type_desc.is_primitive:
        root_array[current_offset: current_offset + true_union_type_desc.size] = generate_primitive_bytearray_number(value= model, type_desc= true_union_type_desc, types_desc= types_desc, offset_size=offset_size)   
    elif current_type_desc.type_type == 'enum':
        root_array[current_offset : current_offset+ true_union_type_desc.size] = generate_enum_type(model= model, types_desc= types_desc, offset_size=offset_size, current_type_desc=true_union_type_desc)  
    elif current_type_desc.type_type == 'struct':
        tail_offset = generate_struct_type(model=model, root_array= root_array, current_offset= current_offset, offset_size= offset_size, array_size= array_size, current_type_desc= true_union_type_desc,tail_offset= tail_offset, types_desc= types_desc)
    return current_offset, tail_offset
        

def generate_string_type(model: str, root_array: bytearray, array_size: int, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int) ->Tuple[int, int]:
    if current_type_desc.name != 'string':
        raise ValueError(f"The type must be of type string instead of {current_type_desc.type_type}")
    current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
    tail_offset = current_offset + offset_size + len(model) + 1
    while(array_size < tail_offset):
        root_array.extend(bytearray(1024))
        array_size += 1024
    root_array[current_offset: current_offset + offset_size] =  generate_primitive_bytearray_number(len(model), get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  offset_size=offset_size, types_desc= types_desc)
    root_array[current_offset + offset_size : current_offset + offset_size + len(model)] = bytearray(model.encode(encoding='utf-8'))
    root_array[current_offset + offset_size + len(model) : current_offset + offset_size + len(model) +1 ] = bytearray([0x00])
    return current_offset, tail_offset
        
def generate_blob_type(model: str, root_array: bytearray, array_size: int, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int) ->Tuple[int, int]:
    pass

def generate_class_type(model: Dict, root_array: bytearray, array_size: int, current_type_desc: TypeDesc, types_desc: set[TypeDesc], current_offset: int, tail_offset: int, offset_size: int):
    pass

def generate_offset_type(model, root_array: bytearray, array_size: int, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int,  true_union_type: str|None, is_array: bool ) -> Tuple[int|None, int]:
    if model == None:
        return None, current_offset
    if is_array:
        return generate_vector_type(model= model, root_array= root_array, array_size= array_size, current_type_desc= current_type_desc, types_desc= types_desc, current_offset= current_offset, offset_size= offset_size)
    elif current_type_desc.type_type == 'union':
        return generate_union_type(model=model, root_array=root_array, array_size= array_size, current_type_desc=  current_type_desc, types_desc= types_desc, current_offset= current_offset, true_union_type= cast(str, true_union_type), offset_size= offset_size)
    elif current_type_desc.name == 'string':
        return generate_string_type(model=model, root_array= root_array, array_size= array_size, current_type_desc= current_type_desc, offset_size= offset_size, types_desc= types_desc, current_offset= current_offset )
    elif current_type_desc.type_type == 'struct_offset':
        current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
        tail_offset = current_offset + current_type_desc.size
        while(array_size < tail_offset):
            root_array.extend(bytearray(1024))
            array_size += 1024
        tail_offset = generate_struct_type(model=model, root_array=root_array,array_size= array_size, current_type_desc= current_type_desc,current_offset=current_offset,  tail_offset= tail_offset, offset_size= offset_size, types_desc= types_desc)
        return current_offset, tail_offset
    elif current_type_desc.type_type == 'class':
        current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
        tail_offset = current_offset + current_type_desc.size
        while(array_size < tail_offset):
            root_array.extend(bytearray(1024))
            array_size += 1024
        generate_class_type(model=model, root_array=root_array,array_size= array_size, current_type_desc= current_type_desc,current_offset=current_offset,  tail_offset= tail_offset, offset_size= offset_size, types_desc= types_desc)
        return current_offset, tail_offset
    else:
        raise ValueError(f"Type of {current_type_desc.name} is not an offset type")


    
     
def generate_struct_type(model: Dict, root_array: bytearray, array_size: int, current_type_desc: TypeDesc, types_desc: set[TypeDesc], current_offset: int, tail_offset: int, offset_size: int) -> int:
    #Not really needed
    current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
    offset_member_map:Dict[str, int|None] = {}
    for member in current_type_desc.members:
        if member.is_offset_type:
            offset_member_map[member.name],tail_offset = generate_offset_type(model[member.name], root_array= root_array, array_size= array_size, current_type_desc= member.type_desc, types_desc=types_desc, current_offset= tail_offset, offset_size= offset_size, is_array= member.is_array,true_union_type= model.get(f'{member.name}_type', None))
    
    for member in current_type_desc.members:
        member_offset = current_offset + member.offset
        if member.name.startswith('pad'):
                root_array[member.offset: member.offset + member.size] = b'\xa5' * member.size
        elif member.is_offset_type:
            value = 0
            if offset_member_map[member.name]  != None:
                value = cast(int, offset_member_map[member.name])- member_offset
            root_array[member_offset : member_offset + member.size] = generate_primitive_bytearray_number(value = value,offset_size= offset_size, type_desc= get_offset_type_desc_int(offset_size=offset_size, types_desc= types_desc), types_desc= types_desc)
        elif member.type_desc.is_primitive:
            root_array[member_offset : member_offset + member.size] = generate_primitive_bytearray_number(value = model[member.name],offset_size= offset_size, type_desc= member.type_desc, types_desc= types_desc)
        elif member.type_desc.type_type == 'enum':
            root_array[member_offset : member_offset + member.size] = generate_enum_type(model= model[member.name],offset_size= offset_size, current_type_desc= member.type_desc, types_desc= types_desc)
        elif member.type_desc.type_type == 'struct':
            tail_offset = generate_struct_type(model = model[member.name], offset_size= offset_size,  tail_offset=tail_offset, root_array=root_array, array_size=array_size, current_type_desc= current_type_desc, types_desc = types_desc, current_offset = current_offset)
        else:
            raise ValueError(f"Type of {current_type_desc.name} is unknown")
    return tail_offset

            
        
            
    
def generate_byte(model, root_type_desc: TypeDesc, offset_size: int, version: int, types_desc: set[TypeDesc]) -> bytearray:
    array_size: int = 1024
    root_array: bytearray = bytearray(array_size)
    
    current_offset: int = 0
    tail_offset: int = 0
    
    current_offset += offset_size
    
    root_array[current_offset: current_offset + offset_size] =  generate_primitive_bytearray_number(value = version,offset_size= offset_size, type_desc= get_offset_type_desc_int(offset_size=offset_size, types_desc= types_desc), types_desc= types_desc)
    current_offset += offset_size
    current_offset += get_padding_size(current_offset, alignment= root_type_desc.alignment)

    tail_offset = current_offset + root_type_desc.size
    while(array_size < tail_offset):
        root_array.extend(bytearray(1024))
        array_size += 1024
        
    tail_offset = generate_struct_type(model = model, offset_size= offset_size, tail_offset=tail_offset, root_array=root_array, array_size=array_size, current_type_desc= root_type_desc, types_desc = types_desc, current_offset = current_offset)
    root_array[0:offset_size] = generate_primitive_bytearray_number(tail_offset, type_desc=  get_offset_type_desc_int(offset_size=offset_size, types_desc= types_desc) , offset_size= offset_size, types_desc= types_desc)
    tail_offset += get_padding_size(tail_offset, alignment=root_type_desc.alignment)
    return root_array[0:tail_offset]
    
    
    
    
    