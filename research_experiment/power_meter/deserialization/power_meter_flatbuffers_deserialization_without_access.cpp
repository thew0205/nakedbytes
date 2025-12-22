#include "power_meter_flatbuffers_generated.h"

void test_function(const uint8_t *buffer, size_t size)
{
    const PowerMeter::MeterData *data = PowerMeter::GetMeterData(buffer);
}

void test_assert(const uint8_t *buffer, size_t size)
{
    assert(true);
}