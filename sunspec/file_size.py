import os

i = 0
sum = 0
model_ids = [id for id in range(0xffff)]
for id in model_ids:
    try:
        model_file_name = f"/home/busoye_tm/Documents/matthew/nakedbytes/models/nakedbytes/binary/nakedbytes_array_model_{id}.bin"
        open(model_file_name, 'r')
    except:
        continue
    i += 1
    nakedbytes_size = os.path.getsize(model_file_name)
    flatbuffer_size = os.path.getsize(f"/home/busoye_tm/Documents/matthew/sunspec_flatbuffer/models/flatbuffer/binary/model_{id}.bin")
    print(f"model {id}: nakedbytes: {nakedbytes_size}\t flatbuffer: {flatbuffer_size}\t difference: {flatbuffer_size - nakedbytes_size}\t %decrement: {int((flatbuffer_size - nakedbytes_size)/ flatbuffer_size * 100)}%\t  %increment: {int((flatbuffer_size - nakedbytes_size)/ nakedbytes_size * 100)}%")
    sum += ((flatbuffer_size - nakedbytes_size)/ flatbuffer_size * 100)
print("model count is ", i, "mean reduction", sum/i)