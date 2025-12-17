


from typing import Dict

"""
Get the required padding size need to required alignment for a type.
"""
def get_padding_size(offset: int, alignment: int) -> int:
    return (alignment - (offset % alignment)) % alignment

def get_next_valid_offset(offset: int, alignment: int) -> int:
    return offset + get_padding_size(offset, alignment)

'''
Basically append all the type defined in the schema file.
'''
def set_all_types(model_def: Dict, all_types: set[str]) -> set[str]:
    for ty in model_def.get('types', []):
        all_types.add(ty['name'])
    return all_types

"""
Return the dictionary definition for a type as provide in the schema
"""
def get_type_from_json(type_name, model_def: Dict) -> Dict:
    
    for model_type in model_def['types']:
        if model_type['name'] == type_name:
            return model_type
    raise ValueError(f"Type name given {type_name} but type definition json not found. Error in model definition.")

"""
Get the int type to be used for the offset type based on the offset size.
"""
def get_offset_type_int(offset_size: int) -> str:
    if offset_size == 1:
        return ('uint8')
    elif offset_size == 2:
        return ('uint16')
    elif offset_size == 4:
        return ('uint32')
    elif offset_size == 8:
        return ('uint64')
    else: 
        return 'uint16'

"""
Get the real object type.
For now only used to strip away the array type array.
"""
def get_real_type_name(type_name: str) -> str:
    first_bracket_index = type_name.find('[')
    last_bracket_index = type_name.find(']')
    if  first_bracket_index != -1 and last_bracket_index != -1:
        type_name = type_name[first_bracket_index+1: last_bracket_index] 
    return type_name

def set_needed_types(root_type: Dict, needed_types: set[str], model_def:Dict ):    
    if root_type['name'] in needed_types:
        return needed_types
    needed_types.add(root_type['name'])
    members = root_type.get('members', [])
    for member in members:
        member_type_name: str = get_real_type_name(member['type'])
        if not member_type_name  in needed_types:
            member_type = get_type_from_json(member_type_name, model_def)
            #? Not needed?
            set_needed_types(member_type, needed_types, model_def)
    members = root_type.get('unions', [])
    for member in members:
        if not member['name']  in needed_types:
            member_type = get_type_from_json(member['name'],model_def)
            #? Not needed?
            set_needed_types(member_type, needed_types, model_def)
            # needed_types.update(set_needed_types(member_type))   
    return needed_types
