import sys
from pathlib import Path
script_dir = Path(__file__).parent
test_dir = script_dir.parent
sys.path.append(f"{test_dir.parent}")

import json
from typing import cast
from code_implementation.byte_generator import generate_byte
from code_implementation.cpp_code_generator_deserializer import generate_cpp_code
from code_implementation.type_desc_holder import TypeDesc, get_type_desc_from_types_desc
from code_implementation.type_parsing import parsing_schema_to_type_desc


model_def_file = f"{script_dir}/array_union.json"
with open(model_def_file, 'r') as f:
    model_def = json.load(f)

root_type_name = model_def['root_type']
version = model_def['version']
offset_size = model_def['offset_size']

types_desc = parsing_schema_to_type_desc(model_def_file)

with open(f"{script_dir}/array_union_generated_class.h", 'wt') as f:
    f.write(generate_cpp_code(types_desc,root_type_name))
      
with open(f"{script_dir}/array_union_data.json", 'r') as f:
    model_data = json.load(f)
    bin = (generate_byte(model=model_data, root_type_desc=cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc)), types_desc= types_desc, offset_size= offset_size, version= version))

    with open(f"{script_dir}/array_union.bin", 'wb') as f:
        f.write(bin)
        
