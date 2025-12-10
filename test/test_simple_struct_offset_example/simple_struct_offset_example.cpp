#include "simple_struct_offset_example_generated_class.h"
#include <stdio.h>

int main()
{
    const char *file_name = "simple_struct_offset_example.bin";
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

    Packet packet{buffer};
    printf("Packet\n");
    printf("id: %d\n", packet.id());
    printf("length: %d\n", packet.length());
    printf("description %d\n", packet.description().value().length());

    if (packet.power_type() == AnyPower_enum_Monster)
    {
        printf("Packet power is monster\n");
    }
    else if (packet.power_type() == AnyPower_enum_Weapon)
    {
        printf("Packet power is weapon\n");
        auto weapon = packet.power().data_as_Weapon();
        printf("name %s\n", weapon.value().name().value().c_str());
    }
    fclose(file);
}