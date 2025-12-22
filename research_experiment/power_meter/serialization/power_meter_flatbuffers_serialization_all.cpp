#include "power_meter_flatbuffers_generated.h"

void test_function()
{
    // Construct a Builder with 1024 byte backing array.
    flatbuffers::FlatBufferBuilder builder(1024);
    builder.Finish(PowerMeter::CreateMeterData(builder, builder.CreateString("matthew777"), 230.5f, 5.2f, 1196.6f, 12345.6f, 50.0f, 0.98f, 1234, builder.CreateString("2025-06-54 06:54:13")));
    // Access one field to measure serialization with one access overhead
    size_t size = builder.GetSize();
    const uint8_t *buffer = builder.GetBufferPointer();
}

size_t test_assert()
{
    // Construct a Builder with 1024 byte backing array.
    flatbuffers::FlatBufferBuilder builder(1024);
    builder.Finish(PowerMeter::CreateMeterData(builder, builder.CreateString("matthew777"), 230.5f, 5.2f, 1196.6f, 12345.6f, 50.0f, 0.98f, 1234, builder.CreateString("2025-06-54 06:54:13")));
    // Access one field to measure serialization with one access overhead
    size_t size = builder.GetSize();
    const uint8_t *buffer = builder.GetBufferPointer();

    const PowerMeter::MeterData *data_deserialized = PowerMeter::GetMeterData(buffer);
    // Access one field to measure serialization with one access overhead
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data_deserialized->voltage();
    volatile float current = data_deserialized->current();
    volatile float power = data_deserialized->power();
    volatile float energy = data_deserialized->energy();
    volatile float freq = data_deserialized->freq();
    volatile float pf = data_deserialized->pf();
    volatile uint16_t alarms = data_deserialized->alarms();
    volatile const char *id = data_deserialized->id()->c_str();
    volatile const char *timestamp = data_deserialized->timestamp()->c_str();

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