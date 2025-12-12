#include "simple_struct_example_generated_class.h"
#include <stdio.h>

size_t get_padding_size(size_t offset, uint16_t alignment)
{
    return (alignment - (offset % alignment)) % alignment;
}

template <typename T>
struct SerializeOffset
{
    uint16_t offset = 0;

    operator SerializeOffset<void>() const
    {
        return SerializeOffset<void>{.offset = offset};
    }
};

struct Serializer
{

#define VERSION 1
#define OFFSET_SIZE 2

    unsigned char *_buffer = nullptr;
    uint16_t _buffer_size = 0;
    // uint16_t _current_offset = 0;
    uint16_t _tail_offset = 0;

    void init(uint16_t buffer_size)
    {
        _buffer = reinterpret_cast<unsigned char *>(malloc(buffer_size));
        _buffer_size = buffer_size;
        // _current_offset += OFFSET_SIZE;
        *reinterpret_cast<uint16_t *>(&_buffer[OFFSET_SIZE]) = VERSION;
        // _current_offset += OFFSET_SIZE;
        // _current_offset += get_padding_size(_current_offset, PACKET_ALIGNMENT);

        _tail_offset = get_padding_size(OFFSET_SIZE * 2, PACKET_ALIGNMENT) + OFFSET_SIZE * 2 + PACKET_SIZE;
        make_buffer_adequate();
    }

    inline void make_buffer_adequate()
    {
        while (_buffer_size < _tail_offset)
        {
            _buffer = reinterpret_cast<unsigned char *>(realloc(_buffer, _buffer_size * 2));
            _buffer_size = _buffer_size * 2;
        }
    }

    SerializeOffset<String> serialize_string(const char *str)
    {
        SerializeOffset<String> str_offset;
        size_t len = strlen(str);
        if (len == 0)
        {
            str_offset.offset = 0;
        }
        else
        {
            _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

            make_buffer_adequate();
            str_offset.offset = _tail_offset;

            *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
            _tail_offset += OFFSET_SIZE;
            memcpy(&_buffer[_tail_offset], str, len + 1);
            _tail_offset += len + 1;
        }
        return str_offset;
    }
};

SerializeOffset<Weapon> serialize_weapon(Serializer *const serializer, const SerializeOffset<String> name, const uint32_t damage)
{
    SerializeOffset<Weapon> weapon_offset;

    serializer->_tail_offset += get_padding_size(serializer->_tail_offset, WEAPON_ALIGNMENT);

    serializer->make_buffer_adequate();
    weapon_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + WEAPON_NAME_OFFSET])) = name.offset - (serializer->_tail_offset + WEAPON_NAME_OFFSET);
    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + WEAPON_DAMAGE_OFFSET])) = damage;
    serializer->_tail_offset += WEAPON_SIZE;
    return weapon_offset;
}

unsigned char *finishPacket(Serializer *const serializer, const int16_t id, const AnyPower_enum anypower_type, const SerializeOffset<void> anypower, const SerializeOffset<String> description, const uint32_t length)
{
    uint16_t current_offset = OFFSET_SIZE * 2 + get_padding_size(OFFSET_SIZE * 2, PACKET_ALIGNMENT);
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[current_offset + PACKET_ID_OFFSET])) = id;
    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset + PACKET_POWER_TYPE_OFFSET])) = anypower_type;
    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset + PACKET_POWER_OFFSET])) = anypower.offset - (current_offset + PACKET_POWER_OFFSET);
    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset + PACKET_DESCRIPTION_OFFSET])) = description.offset - (current_offset + PACKET_DESCRIPTION_OFFSET);
    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[current_offset + PACKET_LENGTH_OFFSET])) = length;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[0])) = serializer->_tail_offset;
    return serializer->_buffer;
}

int main()
{

    Serializer serializer;
    serializer.init(1024);

    auto name = serializer.serialize_string("Matthew :()");
    auto desc = serializer.serialize_string("Nobody can be somebody");
    auto wep = serialize_weapon(&serializer, name, 0xdeadadde);
    auto buf = finishPacket(&serializer, 5, AnyPower_enum_Weapon, wep, desc, 0x55aa);
    const char *file_name = "simple_struct_example.bin";

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

    Packet packet{buf};
    printf("Packet\n");
    printf("id: %d\n", packet.id());
    printf("length: %d\n", packet.length());
    printf("description of len %d: %s\n", packet.description().value().length(), packet.description().value().c_str());

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