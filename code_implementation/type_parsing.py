import json
import struct
from typing import List, Dict, cast

from code_implementation.type_utils import set_all_types, set_needed_types

from .type_desc_holder import *



def parsing_schema_to_type_desc(model_def_file: str):
    model_def = {}
    with open(model_def_file, 'r') as f:
        model_def = json.load(f)
        
    offset_size = model_def.get('offset_size')
    if offset_size == None:
        raise ValueError("offset_size must be defined.")


    all_types= primitive_types.copy()
    needed_types = all_types.copy()

    root_type_name = model_def['root_type']

    root_type = get_type_from_json(root_type_name, model_def)

    set_all_types(model_def, all_types)
    set_needed_types(root_type, needed_types, model_def)
    
    if not needed_types.issubset(all_types):
        raise ValueError("All the needed type must be a subset of all type known.")
    print(needed_types)
    
    types_desc = TypeDesc.get_primitive_types_desc(offset_size=offset_size).copy()
    for i in range(1, 8):
        types_desc.add(TypeDesc.generate_pad(i) )  
    parent_types = []
    types_desc = compute_all_types_desc(types= needed_types, model_def=model_def, offset_size=offset_size, types_desc= types_desc , parent_types=parent_types)
    for t in types_desc:
        print(t,"\n")
    return types_desc
