#include "power_meter_protobuf.pb.h"

void test_function(const uint8_t *buffer, size_t size)
{
    PowerMeter::MeterData data;
    data.ParseFromArray(buffer, size);
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data.voltage();
}

void test_assert(const uint8_t *buffer, size_t size)
{
    PowerMeter::MeterData data;
    data.ParseFromArray(buffer, size);
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data.voltage();

    assert(abs(voltage - 230.5) < 0.01);
}