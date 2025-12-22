#include "power_meter_nakedbytes.nbs.h"
#include <assert.h>

void test_function()
{

    PowerMeter::MeterDataSerializer serializer;
    serializer.init(1024);
    size_t size = serializer.serialize_root(serializer.serialize_string("matthew777"), 230.5f, 5.2f, 1196.6f, 12345.6f, 50.0f, 0.98f, 1234, serializer.serialize_string("2025-06-54 06:54:13"));
    const uint8_t *buffer = serializer.get_buffer();
}

size_t test_assert()
{

    PowerMeter::MeterDataSerializer serializer;
    serializer.init(1024);
    size_t size = serializer.serialize_root(serializer.serialize_string("matthew777"), 230.5f, 5.2f, 1196.6f, 12345.6f, 50.0f, 0.98f, 1234, serializer.serialize_string("2025-06-54 06:54:13"));
    const uint8_t *buffer = serializer.get_buffer();

    const PowerMeter::MeterData *data_deserialized = (PowerMeter::MeterData *)(REMOVE_ROOT(buffer));
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data_deserialized->voltage();
    volatile float current = data_deserialized->current();
    volatile float power = data_deserialized->power();
    volatile float energy = data_deserialized->energy();
    volatile float freq = data_deserialized->freq();
    volatile float pf = data_deserialized->pf();
    volatile uint16_t alarms = data_deserialized->alarms();
    volatile const char *id = data_deserialized->id()->value().c_str();
    volatile const char *timestamp = data_deserialized->timestamp()->value().c_str();

    assert(abs(voltage - 230.5) < 0.01);
    assert(abs(current - 5.2) < 0.001);
    assert(abs(power - 1196.6) < 0.01);
    assert(abs(energy - 12345.6) < 0.01);
    assert(abs(freq - 50.0) < 0.01);
    assert(abs(pf - 0.98) < 0.01);
    assert(alarms == 1234);
    assert(strcmp((const char *)id, "matthew777") == 0);
    assert(strcmp((const char *)timestamp, "2025-06-54 06:54:13") == 0);


    return size;

}