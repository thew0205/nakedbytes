import sys
import argparse
from pathlib import Path
script_dir = Path(__file__).parent
sys.path.append(f"{script_dir.parent}")

import os
import json
from typing import cast
from code_implementation.byte_generator import generate_byte
from code_implementation.cpp_code_generator_deserializer import generate_cpp_code
from code_implementation.type_desc_holder import TypeDesc, get_type_desc_from_types_desc
from code_implementation.type_parsing import parsing

parser = argparse.ArgumentParser(prog='nakedbytes')

parser.add_argument("schema", help= "The schema file defining the nakedbytes.")
parser.add_argument("-b", "--binary", help= "Json file to serialize")
parser.add_argument("-o", "--outbin", help= "output dir to store generated binary files")
parser.add_argument("--cpp", help= "output dir to store generated cpp files")

args = parser.parse_args()


schema_def_file = str(args.schema)
schema_def_file_with_ext = os.path.basename(schema_def_file)
schema_def_file_without_ext = os.path.splitext(schema_def_file_with_ext)[0]

with open(schema_def_file, 'r') as f:
    model_def = json.load(f)   

root_type_name = model_def['root_type']
version = model_def['version']
offset_size = model_def['offset_size']

    
types_desc = parsing(schema_def_file)




if args.cpp:
    with open(Path(f"{args.cpp}").joinpath(f"{schema_def_file_without_ext}.nbs.h"), 'wt') as f:
        f.write(generate_cpp_code(types_desc,root_type_name))
        

if args.binary:
    binary_file = args.binary
    binary_file_with_ext = os.path.basename(binary_file)
    binary_file_without_ext = os.path.splitext(binary_file_with_ext)[0]
    with open(binary_file, 'r') as f:
        model_data = json.load(f)
        bin = (generate_byte(model=model_data, root_type_desc=cast(TypeDesc, get_type_desc_from_types_desc(root_type_name, types_desc)), types_desc= types_desc, offset_size= offset_size, version= version))
        out_bin = args.outbin if args.outbin else os.getcwd()
        with open(Path(f"{out_bin}").joinpath(f"{binary_file_without_ext}.bin"), 'wb') as f:
            f.write(bin)
        
        

    