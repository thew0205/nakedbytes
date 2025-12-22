#!python3

import os
import subprocess
import sys
import json

run_iteration = 3
pwd = os.getcwd()
build_dir = os.path.join(pwd, "build")

def run(cmd, cwd=None) -> str:
    """Run a command and exit on failure (like set -e)."""
    print(f"+ {' '.join(cmd)}")
    result = subprocess.run(cmd, cwd=cwd, check=True, capture_output=True, text=True)
    return result.stdout
    
def analysis_code(key, data_tag) -> dict:
    binary_path = os.path.join(build_dir, f"power_meter_{key}")
    program_results = []
    if os.path.isfile(binary_path):
        print("\n" + "=" * 102)
        print(f"Analyzing for {key} ...")

        # Match bash loop: for i in {1..1}
        for i in range(0, run_iteration):
            if data_tag:
                data_file = os.path.join(
                    pwd, f"power_meter_{data_tag}_data.bin"
                )
                
                result = subprocess.run([binary_path, data_file], cwd=None, check=True, capture_output=True, text=True)
            else:
                result = subprocess.run([binary_path], cwd=None, check=True, capture_output=True, text=True)
            program_results.append(json.loads(result.stdout))


        # size binary
        result = run(["size", binary_path])
        lines = result.strip().splitlines()

        headers = lines[0].split()
        values = lines[1].split(maxsplit=len(headers) - 1)

        size_dict = dict(zip(headers, values))
        
        analysis_result = {"key":key,"program_results": program_results, "size_results": size_dict}
        print(json.dumps(analysis_result,indent = 2 ))
        return analysis_result

    else:
        raise ValueError(f"Error: Program {binary_path} not found!")
            
def analysis_deserialization(program_results: dict):
    for key in program_results:
        if "deserialization" in key:
            pass
    

def main():
    # Configure and build
    run(["cmake", "-S", ".", "-B", "build"])
    run(["cmake", "--build", "build", "-j12"])

    # Program map (ordered like bash associative array is NOT guaranteed,
    # but Python 3.7+ dict preserves insertion order)
    programs = {
        "overhead_deserialization": "overhead",

        "nakedbytes_deserialization_without_access": "nakedbytes",
        "nakedbytes_deserialization_with_one_access": "nakedbytes",
        "nakedbytes_deserialization_with_all_access": "nakedbytes",

        "flatbuffers_deserialization_without_access": "flatbuffers",
        "flatbuffers_deserialization_with_one_access": "flatbuffers",
        "flatbuffers_deserialization_with_all_access": "flatbuffers",

        "protobuf_deserialization_without_access": "protobuf",
        "protobuf_deserialization_with_one_access": "protobuf",
        "protobuf_deserialization_with_all_access": "protobuf",

        "nanopb_deserialization_without_access": "protobuf",
        "nanopb_deserialization_with_one_access": "protobuf",
        "nanopb_deserialization_with_all_access": "protobuf",

        "overhead_serialization": "",

        "nakedbytes_serialization_primitives": "",
        "nakedbytes_serialization_all": "",

        "flatbuffers_serialization_primitives": "",
        "flatbuffers_serialization_all": "",

        "protobuf_serialization_primitives": "",
        "protobuf_serialization_all": "",

        "nanopb_serialization_primitives": "",
        "nanopb_serialization_all": "",
    }

    program_results = {}
    for key, data_tag in programs.items():
       program_results[key] = analysis_code(key=key, data_tag= data_tag)
       
    analysis_deserialization(program_results)


if __name__ == "__main__":
    main()
