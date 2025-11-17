#!/bin/bash
set -e

python3 test_sunspec_model_struct_offset.py

for model in {1..65535}
do  
    if [ -f "models/nakedbytes/binary/nakedbytes_array_model_${model}.bin" ]
    then
        xxd -i -n modelDefinition${model} "models/nakedbytes/binary/nakedbytes_array_model_${model}.bin"  > "models/nakedbytes/nakedbytes/nakedbytes_array_model_${model}.cpp"
        sed -i 's/unsigned char/const unsigned char/g' "models/nakedbytes/nakedbytes/nakedbytes_array_model_${model}.cpp"
        echo "extern const unsigned char modelDefinition${model}[]; " >> models/nakedbytes/nakedbytes/array_models_externs.h
    fi
done
gcc sunspec/sunspec_model_generated_struct_offset.cpp -o sunspec/sunspec_model_generated_struct_offset -g && ./sunspec/sunspec_model_generated_struct_offset 