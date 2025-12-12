import json
from typing import cast
from code_implementation.byte_generator import generate_byte
from code_implementation.cpp_code_generator_deserializer import generate_cpp_code
from code_implementation.type_desc_holder import TypeDesc, get_type_desc_from_types_desc, get_type_from_json, set_all_types, set_needed_types
from code_implementation.type_parsing import parsing, primitive_types

# from pytest import *
# 
# 

model_def_file = "/home/busoye_tm/Documents/matthew/nakedbytes/sunspec/sunspec_model_struct_offset.json"
with open(model_def_file, 'r') as f:
    model_def = json.load(f)

    
def test_set_all_types():
    all_types= primitive_types.copy()

    set_all_types(model_def, all_types)
    assert(all_types==  {'bool', 'uint32', 'SunspecGroupPointDef', 'SunspecModelDef', 'int64', 'int32', 'SunspecPointData', 'float32', 'int8', 'SunspecPointDef', 'uint8', 'char', 'blob', 'uint64', 'float64', 'SunspecPointMandatoryType', 'string', 'uint16', 'int16', 'SunspecGroupType', 'SunspecPointAccessType'})

def test_set_needed_types():
    needed_types= primitive_types.copy()

    root_type_name = model_def['root_type']
    
    root_type = get_type_from_json(root_type_name, model_def)
    
    set_needed_types(root_type, needed_types, model_def)
    assert(needed_types==  {'uint32', 'SunspecGroupPointDef', 'SunspecModelDef', 'int64', 'int32', 'SunspecPointData', 'float32', 'int8', 'SunspecPointDef', 'uint8', 'char', 'blob', 'uint64', 'float64', 'SunspecPointMandatoryType', 'string', 'uint16', 'int16', 'SunspecGroupType', 'SunspecPointAccessType'})
        



all_types= primitive_types.copy()

set_all_types(model_def, all_types)
needed_types= primitive_types.copy()

root_type_name = model_def['root_type']
version = model_def['version']
offset_size = model_def['offset_size']

root_type = get_type_from_json(root_type_name, model_def)
    
set_needed_types(root_type, needed_types, model_def)
types_desc = parsing(model_def_file)
# model_ids = [1, 101, 102, 103, 111, 112, 113, 120, 126, 160]
model_ids = [id for id in range(0xffff)]

for id in model_ids:
    try:
        open(f'models/nakedbytes/json/model_{id}.json', 'r')
    except:
        print(f"Error opening file model_{id}.json")
        continue
        
    with open(f'models/nakedbytes/json/model_{id}.json', 'r') as f:
        model_data = json.load(f)
    bin = (generate_byte(model=model_data, root_type_desc=cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc)), types_desc= types_desc, offset_size= offset_size, version= version))

    with open(f"models/nakedbytes/binary/nakedbytes_array_model_{id}.bin", 'wb') as f:
        f.write(bin)
        
# with open("tflite/tflite_generated.h", 'wt') as f:
#     f.write(generate_cpp_code(types_desc,root_type_name))
        
with open(f'/home/busoye_tm/Documents/matthew/nakedbytes/sunspec/model_1.json', 'r') as f:
    model_data = json.load(f)
    bin = (generate_byte(model=model_data, root_type_desc=cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc)), types_desc= types_desc, offset_size= offset_size, version= version))

    with open(f"sunspec/model_struct_offset.bin", 'wb') as f:
        f.write(bin)
        
with open("sunspec/sunspec_model_generated_struct_offset.h", 'wt') as f:
    f.write(generate_cpp_code(types_desc,root_type_name))