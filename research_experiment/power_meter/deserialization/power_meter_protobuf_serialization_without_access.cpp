#include "power_meter_protobuf.pb.h"

void test_function(const uint8_t *buffer, size_t size)
{
    PowerMeter::MeterData data;
    data.ParseFromArray(buffer, size);
}

void test_assert(const uint8_t *buffer, size_t size)
{
    assert(true);
}