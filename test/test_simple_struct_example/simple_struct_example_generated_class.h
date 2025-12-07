
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define OFFSET_SIZE 2



struct Monster; 
struct Weapon; 
struct AnyPower; 
struct AnyPowerOffset; 
struct Packet; 



struct String
{
    unsigned char *data;

    String(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
#define STRING_LENGTH_OFFSET 0
    uint16_t length() const
    {
        int16_t offset = STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *c_str() const
    {
        uint16_t offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }
};

template<typename T>
struct Offset
{
    unsigned char *data;
    Offset(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }

    T value() const
    {
        int16_t offset = *reinterpret_cast<int16_t *>(data);
        return T(&data[offset]);
    }
};


template <typename T>
struct Union
{
    unsigned char *data;
    Union(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define UNION_TYPE_OFFSET 0
    uint16_t type() const
    {
        return *reinterpret_cast<uint16_t *>(&data[UNION_TYPE_OFFSET]);
    }

#define DATA_OFFSET 2
    const unsigned char *raw_data() const
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) + DATA_OFFSET;

        return (&data[offset]);
    }
    
    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) == 0;
    }
};

template <typename T>
struct Vector
{
    unsigned char *data;

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }
    
    uint16_t size() const
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index) const
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + OFFSET_SIZE * index;
       

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};




struct Monster {

unsigned char * data_;

Monster(unsigned char * data) : data_(data) {}

#define MONSTER_NAME_OFFSET 0


Offset<String> name() const {
const int16_t offset = MONSTER_NAME_OFFSET ;
return Offset<String>(&data_[offset]);
}

};







struct Weapon {

unsigned char * data_;

Weapon(unsigned char * data) : data_(data) {}

#define WEAPON_NAME_OFFSET 0
#define WEAPON_PAD2_OFFSET 2
#define WEAPON_DAMAGE_OFFSET 4


Offset<String> name() const {
const int16_t offset = WEAPON_NAME_OFFSET ;
return Offset<String>(&data_[offset]);
}

uint32_t damage() const {
return *reinterpret_cast<uint32_t*>(&data_[WEAPON_DAMAGE_OFFSET ]);
}

};





enum AnyPower_enum : uint16_t {

AnyPower_enum_Monster,
AnyPower_enum_Weapon,
};

const char * AnyPower_enum_to_string(AnyPower_enum value){
switch (value){
case AnyPower_enum_Monster:
return "AnyPower_enum_Monster";
case AnyPower_enum_Weapon:
return "AnyPower_enum_Weapon";
default:
return NULL;
}
}




struct AnyPower{

unsigned char * data_;

AnyPower(unsigned char * data) : data_(data) {}

#define ANYPOWER_TYPE_OFFSET 0
#define ANYPOWER_DATA_OFFSET 2
AnyPower_enum type() const {
return *reinterpret_cast<AnyPower_enum *>(&data_[ANYPOWER_TYPE_OFFSET]);
}

bool is_null() const {
return (type() == 0) or (*reinterpret_cast<uint16_t *>(&data_[ANYPOWER_DATA_OFFSET]) == 0);
}

unsigned char *raw_data() const {const int16_t offset = *reinterpret_cast<uint16_t *>(&data_[ANYPOWER_DATA_OFFSET]) + ANYPOWER_DATA_OFFSET;
return (&data_[offset]);
}
Monster data_as_Monster() const {
return type() == AnyPower_enum_Monster ? Monster(raw_data()) : 0;
}

Weapon data_as_Weapon() const {
return type() == AnyPower_enum_Weapon ? Weapon(raw_data()) : 0;
}

};





struct Packet {

unsigned char * data_;

Packet(unsigned char * data) : data_(data) {}

#define PACKET_ID_OFFSET 0
#define PACKET_POWER_TYPE_OFFSET 2
#define PACKET_POWER_OFFSET 4
#define PACKET_DESCRIPTION_OFFSET 6
#define PACKET_LENGTH_OFFSET 8


int16_t id() const {
return *reinterpret_cast<int16_t*>(&data_[PACKET_ID_OFFSET + 2* OFFSET_SIZE]);
}

AnyPower_enum power_type() const {
return *reinterpret_cast<AnyPower_enum*>(&data_[PACKET_POWER_TYPE_OFFSET + 2 * OFFSET_SIZE]);
}

AnyPower power() const {
const int16_t offset = PACKET_POWER_OFFSET - 2;
return AnyPower(&data_[offset]);
}

Offset<String> description() const {
const int16_t offset = PACKET_DESCRIPTION_OFFSET + 2* OFFSET_SIZE;
return Offset<String>(&data_[offset]);
}

uint32_t length() const {
return *reinterpret_cast<uint32_t*>(&data_[PACKET_LENGTH_OFFSET + 2* OFFSET_SIZE]);
}

};





