
import struct
from typing import Dict, List, Tuple, cast
from code_implementation.byte_generator_utils import check_and_increment_bytearray, generate_enum_byte, generate_primitive_number_byte, generate_string_byte
from code_implementation.type_desc_holder import  TypeDesc, get_offset_type_desc_int, get_type_desc_from_types_desc
from code_implementation.type_utils import get_padding_size





def generate_vector_type(model: List, root_array: bytearray,  current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int) ->Tuple[int, int]:
    """
    Generate the byte representation of a vector type.
    It store the item count in byte array first and then the items after. If the items are an offset type, the item byte are first generated at the end of the current byte array and the offset to those bytes are stored in the vector item area.
    If the items are primitive type or struct, the item bytes are directly stored in the vector item area.
    """
    item_count =  len(model)
    current_offset += get_padding_size(offset= current_offset, alignment= offset_size)
    root_array[current_offset: current_offset + offset_size] = generate_primitive_number_byte(item_count, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc))
    temp_current_offset = current_offset
    current_offset += offset_size 
    
    if current_type_desc.is_offset_type:
        current_offset += get_padding_size(current_offset, alignment= offset_size)
        
        tail_offset = current_offset + item_count * offset_size
        check_and_increment_bytearray(root_array, tail_offset)

        
        for i, item in enumerate(model):
            item_offset = current_offset + offset_size * i
            real_item_offset, tail_offset = generate_offset_type(model=item, root_array=root_array, current_type_desc=current_type_desc, types_desc= types_desc, current_offset= tail_offset, offset_size=offset_size, is_array= False, true_union_type= None)
            value = 0
            if real_item_offset != None:
                value = real_item_offset - item_offset
                
            root_array[item_offset: item_offset + offset_size] = generate_primitive_number_byte(value, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc))
            
    elif current_type_desc.is_primitive:
        current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
        
        tail_offset = current_offset + current_type_desc.size * item_count
    
        check_and_increment_bytearray(root_array, tail_offset)

        
        for i, item in enumerate(model):
            item_offset = current_offset + current_type_desc.size * i
            root_array[item_offset : item_offset+ current_type_desc.size] = generate_primitive_number_byte(value= item, type_desc= current_type_desc)
    elif current_type_desc.type_type == 'enum':
        current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
        
        tail_offset = current_offset + current_type_desc.size * item_count
        check_and_increment_bytearray(root_array, tail_offset)


        for i, item in enumerate(model):
            item_offset = current_offset + current_type_desc.size * i
            root_array[item_offset : item_offset+ current_type_desc.size] = generate_enum_byte(model= item, types_desc= types_desc, offset_size=current_type_desc.size, current_type_desc=current_type_desc)
    elif current_type_desc.type_type == 'struct':
        current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
        
        tail_offset = current_offset  + current_type_desc.size * item_count
        check_and_increment_bytearray(root_array, tail_offset)

        
        for i, item in enumerate(model):
            item_offset = current_offset + current_type_desc.size * i
            tail_offset = generate_struct_type(model= item, root_array= root_array,  current_type_desc= current_type_desc, types_desc= types_desc, current_offset= item_offset, tail_offset= tail_offset, offset_size=offset_size)
    else: 
        raise ValueError(f"Type of {current_type_desc.name} is unknown")
            
          
    return temp_current_offset, tail_offset

def generate_union_type(model, root_array: bytearray, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int, true_union_type: TypeDesc) ->Tuple[int|None, int]:
    """
    Generate the byte representation for a union type by checking the true union type and generating the byte representation for that type.
    """
    if current_type_desc.type_type != 'union':
        raise ValueError(f"The type must be of type union instead of {current_type_desc.type_type}")
    true_union_type_desc = cast(TypeDesc, get_type_desc_from_types_desc(true_union_type.name, types_desc))
    current_offset += get_padding_size(current_offset, alignment= true_union_type_desc.alignment)
    
    

    # if true_union_type_desc.is_offset_type:
    #     tail_offset = current_offset + offset_size 
    #     check_and_increment_bytearray(root_array, tail_offset)
        
    #     real_item_offset, tail_offset = generate_offset_type(model=model, root_array=root_array, current_type_desc=true_union_type_desc, types_desc= types_desc, current_offset= tail_offset, offset_size=offset_size, is_array= False, true_union_type= None)
    #     value = 0
    #     if real_item_offset != None:
    #         value = real_item_offset - current_offset
    #     root_array[current_offset: current_offset + offset_size] = generate_primitive_number_byte(value, get_offset_type_desc_int(offset_size=offset_size, types_desc=types_desc),  )
    if true_union_type_desc.is_offset_type:
        return generate_offset_type(model=model, root_array=root_array, current_type_desc=true_union_type_desc, types_desc= types_desc, current_offset= current_offset, offset_size=offset_size, is_array= False, true_union_type= None)
        
    elif true_union_type_desc.is_primitive:
        tail_offset = current_offset + true_union_type_desc.size 
        check_and_increment_bytearray(root_array, tail_offset)
        
        root_array[current_offset: current_offset + true_union_type_desc.size] = generate_primitive_number_byte(value= model, type_desc= true_union_type_desc, )   
    elif true_union_type_desc.type_type == 'enum':
        tail_offset = current_offset + true_union_type_desc.size 
        check_and_increment_bytearray(root_array, tail_offset)
        
        root_array[current_offset : current_offset+ true_union_type_desc.size] = generate_enum_byte(model= model, types_desc= types_desc, offset_size=true_union_type_desc.size, current_type_desc=true_union_type_desc)  
    elif true_union_type_desc.type_type == 'struct':
        tail_offset = current_offset + true_union_type_desc.size 
        check_and_increment_bytearray(root_array, tail_offset)
        
        tail_offset = generate_struct_type(model=model, root_array= root_array, current_offset= current_offset, offset_size= offset_size,  current_type_desc= true_union_type_desc,tail_offset= tail_offset, types_desc= types_desc)
    return current_offset, tail_offset
        

        


def generate_class_type(model: Dict, root_array: bytearray,  current_type_desc: TypeDesc, types_desc: set[TypeDesc], current_offset: int, tail_offset: int, offset_size: int) -> int:
    """
    Generate the byte representation for a class type. It first store the size of the class and then generate the byte representation of the class struct type. The alignment for the class must be enforced before calling this function.
    Returns the new tail offset after generating the class type.
    """
    
    root_array[current_offset: current_offset + offset_size] = generate_primitive_number_byte(value = current_type_desc.size , type_desc= get_offset_type_desc_int(offset_size=offset_size, types_desc= types_desc))
    return generate_struct_type(model=model, root_array=root_array, current_type_desc= current_type_desc,current_offset=current_offset,  tail_offset= tail_offset, offset_size= offset_size, types_desc= types_desc)



def generate_offset_type(model, root_array: bytearray, current_type_desc: TypeDesc,  types_desc: set[TypeDesc], current_offset: int,offset_size: int,  true_union_type: str|None, is_array: bool ) -> Tuple[int|None, int]:
    """
    Generate the byte representation for an offset type and appending the bytes to the end of the current byte while enforcing alignment.
    Returns the offset where the bytes were written and the new tail offset after generating the offset type.
    """
    if model == None:
        return None, current_offset
    if is_array:
        return generate_vector_type(model= model, root_array= root_array,  current_type_desc= current_type_desc, types_desc= types_desc, current_offset= current_offset, offset_size= offset_size)
    elif current_type_desc.type_type == 'union':
        return generate_union_type(model=model, root_array=root_array, current_type_desc=  current_type_desc, types_desc= types_desc, current_offset= current_offset, true_union_type = cast(TypeDesc , get_type_desc_from_types_desc(type_name = cast(str, true_union_type), types_desc= types_desc)), offset_size= offset_size)
    elif current_type_desc.name == 'string':
        return generate_string_byte(model=model, root_array= root_array,  current_type_desc= current_type_desc, offset_size= offset_size, types_desc= types_desc, current_offset= current_offset )
    elif current_type_desc.type_type == 'struct_offset':
        current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
        tail_offset = current_offset + current_type_desc.size
        
        check_and_increment_bytearray(root_array, tail_offset)
        
        tail_offset = generate_struct_type(model=model, root_array=root_array, current_type_desc= current_type_desc,current_offset=current_offset,  tail_offset= tail_offset, offset_size= offset_size, types_desc= types_desc)
        return current_offset, tail_offset
    elif current_type_desc.type_type == 'class':
        current_offset += get_padding_size(current_offset, alignment= current_type_desc.alignment)
        tail_offset = current_offset + current_type_desc.size
        
        check_and_increment_bytearray(root_array, tail_offset)
        
        tail_offset = generate_class_type(model=model, root_array=root_array, current_type_desc= current_type_desc,current_offset=current_offset,  tail_offset= tail_offset, offset_size= offset_size, types_desc= types_desc)
        return current_offset, tail_offset
    else:
        raise ValueError(f"Type of {current_type_desc.name} is not an offset type")


    
     
def generate_struct_type(model: Dict, root_array: bytearray,  current_type_desc: TypeDesc, types_desc: set[TypeDesc], current_offset: int, tail_offset: int, offset_size: int) -> int:
    """
    Generate the byte representation for a struct type by iterating through the members and generating the byte representation for each member based on its type.
    It returns the new tail offset after generating the struct type. Alignment for the struct must be enforced before calling this function.
    """
    #Not really needed
    offset_member_map:Dict[str, int|None] = {}
    for member in current_type_desc.members:
        if member.is_offset_type:
            offset_member_map[member.name], tail_offset = generate_offset_type(model[member.name], root_array= root_array,  current_type_desc= member.type_desc, types_desc=types_desc, current_offset= tail_offset, offset_size= offset_size, is_array= member.is_array,true_union_type= model.get(f'{member.name}_type', None))
    
    for member in current_type_desc.members:
        member_offset = current_offset + member.offset
        if member.name.startswith('pad'):
                root_array[member_offset: member_offset + member.size] = b'\xa5' * member.size
        elif member.is_offset_type:
            value = 0
            if offset_member_map[member.name]  != None:
                value = cast(int, offset_member_map[member.name])- member_offset
            root_array[member_offset : member_offset + member.size] = generate_primitive_number_byte(value = value, type_desc= get_offset_type_desc_int(offset_size=offset_size, types_desc= types_desc))
        elif member.type_desc.is_primitive:
            root_array[member_offset : member_offset + member.size] = generate_primitive_number_byte(value = model[member.name], type_desc= member.type_desc)
        elif member.type_desc.type_type == 'enum':
            root_array[member_offset : member_offset + member.size] = generate_enum_byte(model= model[member.name],offset_size= member.type_desc.size, current_type_desc= member.type_desc, types_desc= types_desc)
        elif member.type_desc.type_type == 'struct':
            tail_offset = generate_struct_type(model = model[member.name], offset_size= offset_size,  tail_offset=tail_offset, root_array=root_array,  current_type_desc= member.type_desc, types_desc = types_desc, current_offset = member_offset)
        else:
            raise ValueError(f"Type of {current_type_desc.name} is unknown")
    return tail_offset

            
    
def generate_byte(model, root_type_desc: TypeDesc, offset_size: int, version: int, types_desc: set[TypeDesc]) -> bytearray:
    """
    Generate the byte representation for the model given the root type description, offset size, version and types description set.
    It first creates a bytearray and then generates the byte representation for the root type. It returns the bytearray containing the byte representation of the model.
    It treats the root type as a struct(struct_offset is seen as struct) or class type.
    """
    root_array: bytearray = bytearray(1024)
    
    current_offset: int = 0
    tail_offset: int = 0
    
    current_offset += offset_size
    
    root_array[current_offset: current_offset + offset_size] =  generate_primitive_number_byte(value = version, type_desc= get_offset_type_desc_int(offset_size=offset_size, types_desc= types_desc))
    current_offset += offset_size
    current_offset += get_padding_size(current_offset, alignment= root_type_desc.alignment)

    tail_offset = current_offset + root_type_desc.size
    
    check_and_increment_bytearray(root_array, tail_offset)
  
    if root_type_desc.type_type in ['struct', 'struct_offset']:
        tail_offset = generate_struct_type(model = model, offset_size= offset_size, tail_offset=tail_offset, root_array=root_array,  current_type_desc= root_type_desc, types_desc = types_desc, current_offset = current_offset)
    elif root_type_desc.type_type in ['class']:
        tail_offset = generate_class_type(model = model, offset_size= offset_size, tail_offset=tail_offset, root_array=root_array,  current_type_desc= root_type_desc, types_desc = types_desc, current_offset = current_offset)
    root_array[0:offset_size] = generate_primitive_number_byte(tail_offset, type_desc=  get_offset_type_desc_int(offset_size=offset_size, types_desc= types_desc))
    return root_array[0:tail_offset]
    
    
    
    
    