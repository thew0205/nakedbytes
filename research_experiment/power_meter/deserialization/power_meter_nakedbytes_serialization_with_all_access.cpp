#include "power_meter_nakedbytes.nbs.h"
#include <assert.h>

void test_function(const uint8_t *buffer, size_t size)
{
    const PowerMeter::MeterData *data = (PowerMeter::MeterData *)(REMOVE_ROOT(buffer));
    // Access all fields to measure serialization with all access overhead
    volatile float voltage = data->voltage();
    volatile float current = data->current();
    volatile float power = data->power();
    volatile float energy = data->energy();
    volatile float freq = data->freq();
    volatile float pf = data->pf();
    volatile uint16_t alarms = data->alarms();
    volatile const char *id = data->id()->value().c_str();
    volatile const char *timestamp = data->timestamp()->value().c_str();
}

void test_assert(const uint8_t *buffer, size_t size)
{
    const PowerMeter::MeterData *data = (PowerMeter::MeterData *)(REMOVE_ROOT(buffer));
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data->voltage();
    volatile float current = data->current();
    volatile float power = data->power();
    volatile float energy = data->energy();
    volatile float freq = data->freq();
    volatile float pf = data->pf();
    volatile uint16_t alarms = data->alarms();
    volatile const char *id = data->id()->value().c_str();
    volatile const char *timestamp = data->timestamp()->value().c_str();

    assert(abs(voltage - 230.5) < 0.01);
    assert(abs(current - 5.2) < 0.001);
    assert(abs(power - 1196.6) < 0.01);
    assert(abs(energy - 12345.6) < 0.01);
    assert(abs(freq - 50.0) < 0.01);
    assert(abs(pf - 0.98) < 0.01);
    assert(alarms == 1234);
    assert(strcmp((const char *)id, "matthew777") == 0);
    assert(strcmp((const char *)timestamp, "2025-06-54 06:54:13") == 0);
}