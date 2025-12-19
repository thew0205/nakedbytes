#include <stdio.h>

#include "power_meter.pb.h"
#include <chrono>

void print_power_meter_data(const PZEM004Tv30Data *data)
{
    // if (data == nullptr)
    // {
    //     printf("No data available.\n");
    //     return;
    // }

    //     printf("PZEM004Tv30 Data:\n");
    //     printf("Voltage: %.2f V\n", data->voltage());
    //     printf("Current: %.2f A\n", data->current());
    //     printf("Power: %.2f W\n", data->power());
    //     printf("Energy: %.2f Wh\n", data->energy());
    //     printf("Frequency: %.2f Hz\n", data->freq());
    //     printf("Power Factor: %.2f\n", data->pf());
    //     printf("Alarms: 0x%04X\n", data->alarms());
}

int main()
{
    // // Example buffer containing serialized PZEM004Tv30Data
    // unsigned char buffer[] = {
    //     0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, // voltage = 1.0
    //     0x00, 0x00, 0x00, 0x40,                         // current = 2.0
    //     0x00, 0x00, 0x40, 0x40,                         // power = 3.0
    //     0x00, 0x00, 0x80, 0x40,                         // energy = 4.0
    //     0x00, 0x00, 0xA0, 0x40,                         // freq = 5.0
    //     0x00, 0x00, 0xC0, 0x40,                         // pf = 6.0
    //     0x34, 0x12                                      // alarms = 0x1234
    // };

    const char *file_name = "power_meter_data_protobuf.bin";

    FILE *file = fopen(file_name, "rb");

    fseek(file, 0, SEEK_END);     // Move file pointer to the end
    long file_size = ftell(file); // Get current position (which is the file size)
    fclose(file);
    file = fopen(file_name, "rb");
    uint8_t buffer[file_size];
    int a = fread(buffer, 1, file_size, file);
    if (file_size != a)
    {
        fclose(file);

        return -1;
    }

    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    // Get the root object from the buffer
    for (int i = 0; i < 10000000; i++)
    {
        PZEM004Tv30Data data;
        data.ParseFromArray(buffer, file_size);
        data.ParseFromArray(buffer, file_size);

        // Print the data
        // print_power_meter_data(data);
        data.voltage();
        data.current();
        data.power();
        data.energy();
        data.freq();
        data.pf();
        data.alarms();
    }

    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    printf("Time taken to deserialize: %ldms %f\n", ms_int.count(), ms_double.count());
    // std::cout << ms_int.count() << "ms\n";
    // std::cout << ms_double.count() << "ms\n";

    return 0;
}