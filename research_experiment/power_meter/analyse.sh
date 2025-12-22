set -e
# PROGRAM_NAME=$1
# BINARY_FILE=$2

PWD=$(pwd)

cmake -S . -B build
cmake --build build -j12

# clear
declare -A programs
programs=(
    # ["overhead_deserialization"]="overhead"
    
    # ["nakedbytes_deserialization_without_access"]="nakedbytes"
    # ["nakedbytes_deserialization_with_one_access"]="nakedbytes"
    # ["nakedbytes_deserialization_with_all_access"]="nakedbytes"

    # ["flatbuffers_deserialization_without_access"]="flatbuffers"
    # ["flatbuffers_deserialization_with_one_access"]="flatbuffers"
    # ["flatbuffers_deserialization_with_all_access"]="flatbuffers"
   
    # ["protobuf_deserialization_without_access"]="protobuf"
    # ["protobuf_deserialization_with_one_access"]="protobuf"
    # ["protobuf_deserialization_with_all_access"]="protobuf"
    
    # ["nanopb_deserialization_without_access"]="protobuf"
    # ["nanopb_deserialization_with_one_access"]="protobuf"
    # ["nanopb_deserialization_with_all_access"]="protobuf"


    ["overhead_serialization"]=""

    # ["nakedbytes_serialization_primitives"]=""
    # ["nakedbytes_serialization_all"]=""

    ["flatbuffers_serialization_primitives"]=""
    # ["flatbuffers_serialization_all"]=""

    ["protobuf_serialization_primitives"]=""
    # ["protobuf_serialization_all"]=""

    # ["nanopb_serialization_primitives"]=""
    # ["nanopb_serialization_all"]=""


)

for key in "${!programs[@]}"; do
    if [ -f $PWD/build/power_meter_${key} ]; then
        echo  && echo "======================================================================================================" 
        echo "Analyzing for ${key} ..."
        for i in {1..1}; do
            echo "Run $i:"
            $PWD/build/power_meter_${key} $PWD/power_meter_${programs[$key]}_data.bin
        done
        size $PWD/build/power_meter_${key}

    else
        echo "Error: Program $PWD/build/power_meter_${key} not found!"
    fi
done

# if [ -f $PWD/build/power_meter_${PROGRAM_NAME} ]; then
#     echo "Analyzing for ${PROGRAM_NAME} ..."
#     $PWD/build/power_meter_${PROGRAM_NAME} $PWD/power_meter_data_${BINARY_FILE}.bin
#     size $PWD/build/power_meter_${PROGRAM_NAME}

# else
#     echo "Error: Program $PWD/build/power_meter_${PROGRAM_NAME} not found!"
# fi