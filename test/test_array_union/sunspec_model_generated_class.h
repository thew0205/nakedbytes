
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define OFFSET_SIZE 2



struct AnyMessage; 
struct AnyMessageOffset; 
struct Monster; 
struct MonsterOffset; 
struct Weapon; 
struct WeaponOffset; 
struct Packet; 
struct PacketOffset; 



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


enum AnyMessage_enum : uint16_t {

AnyMessage_enum_Monster,
AnyMessage_enum_Weapon,
};

const char * AnyMessage_enum_to_string(AnyMessage_enum value){
switch (value){
case AnyMessage_enum_Monster:
return "AnyMessage_enum_Monster";
case AnyMessage_enum_Weapon:
return "AnyMessage_enum_Weapon";
default:
return NULL;
}
}




struct Monster {

unsigned char * data_;

Monster(unsigned char * data) : data_(data) {}

#define MONSTER_NAME_OFFSET 0


Offset<String> name() const {
const int16_t offset = MONSTER_NAME_OFFSET ;
return Offset<String>(&data_[offset]);
}

};



struct MonsterOffset {

unsigned char * data_;

MonsterOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Monster value(){
 const int16_t offset = *reinterpret_cast<int16_t *>(data_);
return Monster(&data_[offset]);
}
};

struct Weapon {

unsigned char * data_;

Weapon(unsigned char * data) : data_(data) {}

#define WEAPON_NAME_OFFSET 0
#define WEAPON_DAMAGE_OFFSET 2


Offset<String> name() const {
const int16_t offset = WEAPON_NAME_OFFSET ;
return Offset<String>(&data_[offset]);
}

int16_t damage() const {
return *reinterpret_cast<int16_t*>(&data_[WEAPON_DAMAGE_OFFSET ]);
}

};



struct WeaponOffset {

unsigned char * data_;

WeaponOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Weapon value(){
 const int16_t offset = *reinterpret_cast<int16_t *>(data_);
return Weapon(&data_[offset]);
}
};

struct AnyMessage{

unsigned char * data_;

AnyMessage(unsigned char * data) : data_(data) {}

#define ANYMESSAGE_TYPE_OFFSET 0
#define ANYMESSAGE_DATA_OFFSET 2
AnyMessage_enum type() const {
return *reinterpret_cast<AnyMessage_enum *>(&data_[ANYMESSAGE_TYPE_OFFSET]);
}

bool is_null() const {
return (type() == 0) or (*reinterpret_cast<uint16_t *>(&data_[ANYMESSAGE_DATA_OFFSET]) == 0);
}

unsigned char *raw_data() const {const int16_t offset = *reinterpret_cast<uint16_t *>(&data_[ANYMESSAGE_DATA_OFFSET]) + ANYMESSAGE_DATA_OFFSET;
return (&data_[offset]);
}
Offset<Monster> data_as_Monster() const {
return type() == AnyMessage_enum_Monster ? Offset<Monster>(raw_data()) : 0;
}

Offset<Weapon> data_as_Weapon() const {
return type() == AnyMessage_enum_Weapon ? Offset<Weapon>(raw_data()) : 0;
}

};









struct Packet {

unsigned char * data_;

Packet(unsigned char * data) : data_(data) {}

#define PACKET_ID_OFFSET 0
#define PACKET_DATA_OFFSET 2


int16_t id() const {
return *reinterpret_cast<int16_t*>(&data_[PACKET_ID_OFFSET + 2* OFFSET_SIZE]);
}

Vector<AnyMessage> data() const {
const int16_t offset = PACKET_DATA_OFFSET + 2* OFFSET_SIZE;
return Vector<AnyMessage>(&data_[offset]);
}

};



struct PacketOffset {

unsigned char * data_;

PacketOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Packet value(){
 const int16_t offset = *reinterpret_cast<int16_t *>(data_);
return Packet(&data_[offset]);
}
};

