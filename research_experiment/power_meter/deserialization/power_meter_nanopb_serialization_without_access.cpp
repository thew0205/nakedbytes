#include "power_meter_nanopb.pb.h"

#include <pb_decode.h>
#include <assert.h>

void test_function(const uint8_t *buffer, size_t size)
{
    PowerMeter_MeterData data;
    pb_istream_t stream = pb_istream_from_buffer(buffer, size);
    pb_decode(&stream, PowerMeter_MeterData_fields, &data);
}

void test_assert(const uint8_t *buffer, size_t size)
{
    assert(true);
}