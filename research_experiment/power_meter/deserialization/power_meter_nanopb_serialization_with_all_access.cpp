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
    volatile float current = data.current;
    volatile float power = data.power;
    volatile float energy = data.energy;
    volatile float freq = data.freq;
    volatile float pf = data.pf;
    volatile uint16_t alarms = data.alarms;
    volatile const char * id = data.id;
    volatile const char * timestamp = data.timestamp;
}

void test_assert(const uint8_t *buffer, size_t size)
{
    PowerMeter_MeterData data = PowerMeter_MeterData_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(buffer, size);
    pb_decode(&stream, PowerMeter_MeterData_fields, &data);
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data.voltage;
    volatile float current = data.current;
    volatile float power = data.power;
    volatile float energy = data.energy;
    volatile float freq = data.freq;
    volatile float pf = data.pf;
    volatile uint16_t alarms = data.alarms;
    volatile const char * id = data.id;
    volatile const char * timestamp = data.timestamp;

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