#include "simple_struct_offset_example.nbs.h"
#include <stdio.h>
using namespace nakedbytes;
int main()
{
    PacketSerializer serializer;
    serializer.init(255);

    // auto name = serializer.serialize_string("Matthew :()");
    // auto wep = serialize_weapon(&serializer, name, 0xdeadadde);

    // auto desc = serializer.serialize_string("Nobody can be somebody");

    // auto you = serialize_monster(&serializer, name);

    // auto pos = serializer.serialize_vector(std::vector<uint16_t>{1, 4, 7});
    // auto wepField = WeaponStruct{.name = desc, .damage = 2345};

    // auto arr_wep = serializer.serialize_vector(std::vector<SerializeOffset<Weapon>>{wep});
    // auto buf = serializer.serialize_root(5, AnyPower_enum_Weapon, wep, desc, 5599, pos, you, arr_wep);

    const char *file_name = "/home/busoye_tm/Documents/matthew/projects/nakedbytes/test/test_simple_struct_offset_example/simple_struct_offset_example_data.bin";
    FILE *file = fopen(file_name, "rb");

    fseek(file, 0, SEEK_END);   // Move file pointer to the end
    long file_si = ftell(file); // Get current position (which is the file size)
    unsigned long file_size = (unsigned long)file_si;
    fclose(file);
    file = fopen(file_name, "rb");
    uint8_t buffer[10000];
    size_t a = fread(buffer, 1, file_size, file);
    if (file_size != a)
    {
        fclose(file);

        return -1;
    }

    const Packet &packet = *GetRootPacket(buffer);
    printf("Packet\n");
    printf("id: %d\n", packet.id());
    printf("length: %d\n", packet.length());
    printf("description of len %lu: %s\n", packet.description()->value().length(), packet.description()->value().c_str());

    if (packet.power_type() == AnyPower_enum_Monster)
    {
        printf("Packet power is monster\n");
    }
    else if (packet.power_type() == AnyPower_enum_Weapon)
    {
        printf("Packet power is weapon\n");
        auto weapon = packet.power()->data_as_Weapon()->value_ptr();
        printf("%x name %s\n", weapon->damage(), weapon->name()->value().c_str());
    }

    for (uint8_t i = 0; i < packet.pos()->size(); i++)
    {
        printf("%d, ", packet.pos()->get(i));
    }
    printf("\n");
    for (auto ab : *packet.pos())
    {
        printf("%d, ", ab);
    }

    printf("\n");
    printf("A monster named %s\n", packet.you()->value().name()->value().c_str());

    for (uint8_t i = 0; i < packet.arsenal()->size(); i++)
    {
        printf("name %u %u, %s\n", i, packet.arsenal()->get(i).value().damage(), packet.arsenal()->get(i).value().name()->value().c_str());
    }
    fclose(file);
}