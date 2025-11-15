#!/bin/bash

python3 test_sunspec_model_struct_offset.py
xxd -i -n modelDefinition sunspec/model_struct_offset.bin  > sunspec/model_struct_offset_1.h
gcc sunspec/sunspec_model_generated_class.cpp -o sunspec/sunspec_model_generated_struct_offset -g && ./sunspec/sunspec_model_generated_struct_offset 