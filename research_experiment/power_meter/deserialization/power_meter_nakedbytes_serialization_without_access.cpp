#include "power_meter_nakedbytes.nbs.h"
#include <assert.h>

void test_function(const uint8_t *buffer, size_t size)
{
    const PowerMeter::MeterData *data = (PowerMeter::MeterData *)(REMOVE_ROOT(buffer));
}

void test_assert(const uint8_t *buffer, size_t size)
{
    assert(true);
}