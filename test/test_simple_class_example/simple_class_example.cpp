#include "simple_class_example_generated_class.h"
#include <stdio.h>

int main()
{

      Serializer serializer;
    serializer.init(1024);

    auto name = serializer.serialize_string("Matthew :()");
    auto desc = serializer.serialize_string("Nobody can be somebody");
    auto wep = serialize_weapon(&serializer, name, 0xdeadadde);
    auto buf = serialize_packet_root(&serializer, 5, AnyPower_enum_Weapon, wep, desc, 0x55aa);

    const char *file_name = "simple_class_example.bin";
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

    PacketRoot packet{buf};
    printf("Packet\n");
    printf("id: %d\n", packet.id());
    printf("length: %d\n", packet.length());
    printf("length: %s\n", packet.description().value().c_str());
    printf("description %d\n", packet.description().value().length());

    if (packet.power_type() == AnyPower_enum_Monster)
    {
        printf("Packet power is monster\n");
    }
    else if (packet.power_type() == AnyPower_enum_Weapon)
    {
        printf("Packet power is Weapon\n");
        auto weapon = packet.power().data_as_Weapon();
        printf("name %s\n", weapon.value().name().value().c_str());
    }
    fclose(file);
}