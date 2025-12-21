set -e
# PROGRAM_NAME=$1
# BINARY_FILE=$2

PWD=$(pwd)

cmake -S . -B build
cmake --build build  

# clear
declare -A programs
programs=(
    ["overhead"]="overhead"
    
    ["nakedbytes_serialization_without_access"]="nakedbytes"
    ["nakedbytes_serialization_with_one_access"]="nakedbytes"
    ["nakedbytes_serialization_with_all_access"]="nakedbytes"

    ["flatbuffers_serialization_without_access"]="flatbuffers"
    ["flatbuffers_serialization_with_one_access"]="flatbuffers"
    ["flatbuffers_serialization_with_all_access"]="flatbuffers"
   
    ["protobuf_serialization_without_access"]="protobuf"
    ["protobuf_serialization_with_one_access"]="protobuf"
    ["protobuf_serialization_with_all_access"]="protobuf"
    
    ["nanopb_serialization_without_access"]="protobuf"
    ["nanopb_serialization_with_one_access"]="protobuf"
    ["nanopb_serialization_with_all_access"]="protobuf"
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