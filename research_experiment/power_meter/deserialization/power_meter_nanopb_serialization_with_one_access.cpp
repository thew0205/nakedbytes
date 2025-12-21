#include "power_meter_nanopb.pb.h"

#include <pb_decode.h>
#include <assert.h>
#include <stdlib.h>

void test_function(const uint8_t *buffer, size_t size)
{
    PowerMeter_MeterData data;
    pb_istream_t stream = pb_istream_from_buffer(buffer, size);
    pb_decode(&stream, PowerMeter_MeterData_fields, &data);
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data.voltage;
}

void test_assert(const uint8_t *buffer, size_t size)
{
    PowerMeter_MeterData data;
    pb_istream_t stream = pb_istream_from_buffer(buffer, size);
    pb_decode(&stream, PowerMeter_MeterData_fields, &data);
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data.voltage;

    assert(abs(voltage - 230.5) < 0.01);
}