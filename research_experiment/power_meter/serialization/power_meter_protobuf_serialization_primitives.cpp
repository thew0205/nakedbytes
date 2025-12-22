#include "power_meter_protobuf.pb.h"

void test_function()
{

    PowerMeter::MeterData data;
    data.set_voltage(230.5f);
    data.set_current(5.2f);
    data.set_power(1196.6f);
    data.set_energy(12345.6f);
    data.set_freq(50.0f);
    data.set_pf(0.98f);
    data.set_alarms(1234);
    const auto serialized_data = data.SerializeAsString();
    const uint8_t *buffer = reinterpret_cast<const uint8_t *>(serialized_data.data());
    size_t size = serialized_data.size();
}

size_t test_assert()
{
    PowerMeter::MeterData data;
    data.set_voltage(230.5f);
    data.set_current(5.2f);
    data.set_power(1196.6f);
    data.set_energy(12345.6f);
    data.set_freq(50.0f);
    data.set_pf(0.98f);
    data.set_alarms(1234);
    const auto serialized_data = data.SerializeAsString();
    const uint8_t *buffer = reinterpret_cast<const uint8_t *>(serialized_data.data());
    size_t size = serialized_data.size();

    PowerMeter::MeterData data_deserialized;
    data_deserialized.ParseFromArray(buffer, size);
    // Access one field to measure serialization with one access overhead
    volatile float voltage = data_deserialized.voltage();
    volatile float current = data_deserialized.current();
    volatile float power = data_deserialized.power();
    volatile float energy = data_deserialized.energy();
    volatile float freq = data_deserialized.freq();
    volatile float pf = data_deserialized.pf();
    volatile uint16_t alarms = data_deserialized.alarms();

    assert(abs(voltage - 230.5) < 0.01);
    assert(abs(current - 5.2) < 0.001);
    assert(abs(power - 1196.6) < 0.01);
    assert(abs(energy - 12345.6) < 0.01);
    assert(abs(freq - 50.0) < 0.01);
    assert(abs(pf - 0.98) < 0.01);
    assert(alarms == 1234);


    return size;

}