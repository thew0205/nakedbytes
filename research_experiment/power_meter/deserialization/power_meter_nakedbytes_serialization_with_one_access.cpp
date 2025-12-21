#include "power_meter_nakedbytes.nbs.h"
#include <assert.h>

void test_function(const uint8_t *buffer, size_t size)
{
    const PowerMeter::MeterData *data = (PowerMeter::MeterData *)(REMOVE_ROOT(buffer));
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data->voltage();
}

void test_assert(const uint8_t *buffer, size_t size)
{
    const PowerMeter::MeterData *data = (PowerMeter::MeterData *)(REMOVE_ROOT(buffer));
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data->voltage();

    assert(abs(voltage - 230.5) < 0.01);
}