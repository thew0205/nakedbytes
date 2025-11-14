import os

model_ids = [id for id in range(0xffff)]
for id in model_ids:
    try:
        open(f"/home/busoye_tm/Documents/matthew/nakedbytes/binary/model_{id}.bin", 'r')
    except:
        continue
    nakedbytes_size = os.path.getsize(f"/home/busoye_tm/Documents/matthew/nakedbytes/binary/model_{id}.bin")
    flatbuffer_size = os.path.getsize(f"/home/busoye_tm/Documents/matthew/sunspec_flatbuffer/models/flatbuffer/binary/model_{id}.bin")
    print(f"model {id}: nakedbytes: {nakedbytes_size}\t flatbuffer: {flatbuffer_size}\t difference: {flatbuffer_size - nakedbytes_size}\t %decrement: {int((flatbuffer_size - nakedbytes_size)/ flatbuffer_size * 100)}%\t  %increment: {int((flatbuffer_size - nakedbytes_size)/ nakedbytes_size * 100)}%")