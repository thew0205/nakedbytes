#include "power_meter_nanopb.pb.h"

#include <pb_decode.h>
#include <pb_encode.h>
#include <assert.h>
#include <stdlib.h>

void test_function()
{
    PowerMeter_MeterData data = {.voltage = 230.5f, .current = 5.2f, .power = 1196.6f, .energy = 12345.6f, .freq = 50.0f, .pf = 0.98f, .alarms = 1234};
    uint8_t buffer[1024];
    pb_ostream_t stream = pb_ostream_from_buffer(buffer,  sizeof(buffer));
    pb_encode(&stream, PowerMeter_MeterData_fields, &data);
    size_t size = stream.bytes_written;

}

size_t test_assert()
{

    PowerMeter_MeterData data = {.voltage = 230.5f, .current = 5.2f, .power = 1196.6f, .energy = 12345.6f, .freq = 50.0f, .pf = 0.98f, .alarms = 1234};
    uint8_t buffer[1024];
    pb_ostream_t stream = pb_ostream_from_buffer(buffer,  sizeof(buffer));
    pb_encode(&stream, PowerMeter_MeterData_fields, &data);
    size_t size = stream.bytes_written;

    // Access one field to measure serialization with one access overhead

    PowerMeter_MeterData data_deserialized;
    pb_istream_t stream_deserialized = pb_istream_from_buffer(buffer, size);
    pb_decode(&stream_deserialized, PowerMeter_MeterData_fields, &data_deserialized);
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data_deserialized.voltage;
    volatile float current = data_deserialized.current;
    volatile float power = data_deserialized.power;
    volatile float energy = data_deserialized.energy;
    volatile float freq = data_deserialized.freq;
    volatile float pf = data_deserialized.pf;
    volatile uint16_t alarms = data_deserialized.alarms;


    assert(abs(voltage - 230.5) < 0.01);
    assert(abs(current - 5.2) < 0.001);
    assert(abs(power - 1196.6) < 0.01);
    assert(abs(energy - 12345.6) < 0.01);
    assert(abs(freq - 50.0) < 0.01);
    assert(abs(pf - 0.98) < 0.01);
    assert(alarms == 1234);

    return size;

}