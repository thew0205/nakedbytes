
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <type_traits>
#include <vector>

#define OFFSET_SIZE 2



struct Monster; 
struct Weapon; 
struct Packet; 
struct AnyPower; 






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
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *c_str() const
    {
        uint16_t offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }
};

template<typename T, typename Enable = void>
struct Offset
{
    static constexpr size_t nakedbytes_sizeof = 2;
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
        int16_t offset = *reinterpret_cast<int16_t *>(&data[0]);
        return T(&data[offset]);
    }
};

template<typename T>
struct Offset<T, typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value)>::type>
{
    static constexpr size_t nakedbytes_sizeof = sizeof(T);
    
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
        int16_t offset = *reinterpret_cast<int16_t *>(&data[0]);
        return static_cast<T>(data[offset]);
    }
};

template<typename T> struct is_Offset_Type : std::false_type {};
template<typename T>
struct is_Offset_Type<Offset<T>> : std::true_type {};


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

template<typename T, typename Enable = void>
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
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + T::nakedbytes_sizeof * index;
       

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};

template<typename T>
struct Vector<T, typename std::enable_if<(std::is_floating_point<T>::value || std::is_integral<T>::value)>::type>
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
       

        return static_cast<T>(data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};





struct Monster {

static constexpr size_t nakedbytes_sizeof = 2;

unsigned char * data_;

Monster(unsigned char * data) : data_(data) {}

#define MONSTER_NAME_OFFSET 0
#define MONSTER_ALIGNMENT 2
#define MONSTER_SIZE 2


Offset<String> name() const {
const int16_t offset = MONSTER_NAME_OFFSET ;
return Offset<String>(&data_[offset]);
}

};







struct Weapon {

static constexpr size_t nakedbytes_sizeof = 8;

unsigned char * data_;

Weapon(unsigned char * data) : data_(data) {}

#define WEAPON_NAME_OFFSET 0
#define WEAPON_PAD2_OFFSET 2
#define WEAPON_DAMAGE_OFFSET 4
#define WEAPON_ALIGNMENT 4
#define WEAPON_SIZE 8


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

inline const char * AnyPower_enum_to_string(AnyPower_enum value){
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
#define ANYPOWER_ALIGNMENT 2
#define ANYPOWER_SIZE 2


bool is_null() const {
return (type() == 0) or (*reinterpret_cast<uint16_t *>(&data_[ANYPOWER_DATA_OFFSET]) == 0);
}

unsigned char *raw_data() const {const int16_t offset = *reinterpret_cast<uint16_t *>(&data_[ANYPOWER_DATA_OFFSET]) + ANYPOWER_DATA_OFFSET;
return (&data_[offset]);
}
AnyPower_enum type() const {
return *reinterpret_cast<AnyPower_enum *>(&data_[ANYPOWER_TYPE_OFFSET]);
}

Offset<Monster> data_as_Monster() const {
return type() == AnyPower_enum_Monster ? Offset<Monster>(&data_[ANYPOWER_DATA_OFFSET]) : 0;
}

Offset<Weapon> data_as_Weapon() const {
return type() == AnyPower_enum_Weapon ? Offset<Weapon>(&data_[ANYPOWER_DATA_OFFSET]) : 0;
}

};



struct Packet {

static constexpr size_t nakedbytes_sizeof = 20;

unsigned char * data_;

Packet(unsigned char * data) : data_(data) {}

#define PACKET_ID_OFFSET 0
#define PACKET_POWER_TYPE_OFFSET 2
#define PACKET_POWER_OFFSET 4
#define PACKET_DESCRIPTION_OFFSET 6
#define PACKET_LENGTH_OFFSET 8
#define PACKET_POS_OFFSET 12
#define PACKET_YOU_OFFSET 14
#define PACKET_ARSENAL_OFFSET 16
#define PACKET_PAD18_OFFSET 18
#define PACKET_ALIGNMENT 4
#define PACKET_SIZE 20


int16_t id() const {
return *reinterpret_cast<int16_t*>(&data_[PACKET_ID_OFFSET ]);
}

AnyPower_enum power_type() const {
return *reinterpret_cast<AnyPower_enum*>(&data_[PACKET_POWER_TYPE_OFFSET ]);
}

AnyPower power() const {
const int16_t offset = PACKET_POWER_OFFSET - 2 ;
return AnyPower(&data_[offset]);
}

Offset<String> description() const {
const int16_t offset = PACKET_DESCRIPTION_OFFSET ;
return Offset<String>(&data_[offset]);
}

uint32_t length() const {
return *reinterpret_cast<uint32_t*>(&data_[PACKET_LENGTH_OFFSET ]);
}

Vector<uint16_t> pos() const {
const int16_t offset = PACKET_POS_OFFSET ;
return Vector<uint16_t>(&data_[offset]);
}

Offset<Monster> you() const {const int16_t offset =PACKET_YOU_OFFSET ;return Offset<Monster>(&data_[offset]);}

Vector<Offset<Weapon>> arsenal() const {
const int16_t offset = PACKET_ARSENAL_OFFSET ;
return Vector<Offset<Weapon>>(&data_[offset]);
}

};











struct PacketRoot {

unsigned char * data_;

PacketRoot(unsigned char * data) : data_(data) {}

#define PACKET_ID_OFFSET 0
#define PACKET_POWER_TYPE_OFFSET 2
#define PACKET_POWER_OFFSET 4
#define PACKET_DESCRIPTION_OFFSET 6
#define PACKET_LENGTH_OFFSET 8
#define PACKET_POS_OFFSET 12
#define PACKET_YOU_OFFSET 14
#define PACKET_ARSENAL_OFFSET 16
#define PACKET_PAD18_OFFSET 18
#define PACKET_ALIGNMENT 4
#define PACKET_SIZE 20


int16_t id() const {
return *reinterpret_cast<int16_t*>(&data_[PACKET_ID_OFFSET + 2* OFFSET_SIZE]);
}

AnyPower_enum power_type() const {
return *reinterpret_cast<AnyPower_enum*>(&data_[PACKET_POWER_TYPE_OFFSET + 2 * OFFSET_SIZE]);
}

AnyPower power() const {
const int16_t offset = PACKET_POWER_OFFSET - 2 + 2* OFFSET_SIZE;
return AnyPower(&data_[offset]);
}

Offset<String> description() const {
const int16_t offset = PACKET_DESCRIPTION_OFFSET + 2* OFFSET_SIZE;
return Offset<String>(&data_[offset]);
}

uint32_t length() const {
return *reinterpret_cast<uint32_t*>(&data_[PACKET_LENGTH_OFFSET + 2* OFFSET_SIZE]);
}

Vector<uint16_t> pos() const {
const int16_t offset = PACKET_POS_OFFSET + 2* OFFSET_SIZE;
return Vector<uint16_t>(&data_[offset]);
}

Offset<Monster> you() const {const int16_t offset =PACKET_YOU_OFFSET + 2* OFFSET_SIZE;return Offset<Monster>(&data_[offset]);}

Vector<Offset<Weapon>> arsenal() const {
const int16_t offset = PACKET_ARSENAL_OFFSET + 2* OFFSET_SIZE;
return Vector<Offset<Weapon>>(&data_[offset]);
}

};





inline size_t get_padding_size(size_t offset, uint16_t alignment)
{
    return (alignment - (offset % alignment)) % alignment;
}

template <typename T>
struct SerializeOffset
{
    uint16_t offset = 0;

    template<typename U = void>
    operator SerializeOffset<U>() const
    {
        SerializeOffset<U> ret;
        ret.offset = this->offset;
        return ret;
    }
};

template <typename T>
struct is_serializable_offset_Type : std::false_type
{
};
template <typename T>
struct is_serializable_offset_Type<SerializeOffset<T>> : std::true_type
{
};

struct Serializer
{

#define VERSION 1
#define OFFSET_SIZE 2

    unsigned char *_buffer = nullptr;
    uint16_t _buffer_size = 0;
    // uint16_t _current_offset = 0;
    uint16_t _tail_offset = 0;

    void init(uint16_t buffer_size, const uint16_t root_type_size, uint16_t root_type_alignment)
    {
        _buffer = reinterpret_cast<unsigned char *>(malloc(buffer_size));
        _buffer_size = buffer_size;
        *reinterpret_cast<uint16_t *>(&_buffer[OFFSET_SIZE]) = VERSION;

        _tail_offset = get_padding_size(OFFSET_SIZE * 2, root_type_alignment) + OFFSET_SIZE * 2 + root_type_size;
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
        
        if (str == nullptr)
        {
            str_offset.offset = 0;
        }
        else
        {
            size_t len = strlen(str);
            _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

            make_buffer_adequate();
            str_offset.offset = _tail_offset;

            *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
            _tail_offset += OFFSET_SIZE;
            memcpy(&_buffer[_tail_offset], str, len);
            *reinterpret_cast<unsigned char *>(&(((unsigned char *)_buffer)[_tail_offset + len])) = 0;
            _tail_offset += len + 1;
        }
        return str_offset;
    }
    
    template <typename T>
    typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_enum<T>::value), SerializeOffset<T>>::type serialize_primitive(T data)
    {
        SerializeOffset<T> data_offset;
        _tail_offset += get_padding_size(_tail_offset, sizeof(T));

        make_buffer_adequate();
        data_offset.offset = _tail_offset;

        *reinterpret_cast<T *>(&_buffer[_tail_offset]) = data;

        return data_offset;
    }
    
     template <typename>
    struct extract_vector_type
    {
    };

    template <typename T, typename Alloc>
    struct extract_vector_type<std::vector<T, Alloc>>
    {
        using type = T;
    };

    template <typename Vec>
    using vec_inner_t = typename extract_vector_type<Vec>::type;

    template <typename T>
    typename std::enable_if<(std::is_integral<vec_inner_t<T>>::value || std::is_floating_point<vec_inner_t<T>>::value || std::is_enum<vec_inner_t<T>>::value), SerializeOffset<Vector<vec_inner_t<T>>>>::type serialize_vector(T data_array)
    {
        SerializeOffset<Vector<vec_inner_t<T>>> data_array_offset;
        size_t len = data_array.size();
        _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

        make_buffer_adequate();
        data_array_offset.offset = _tail_offset;

        *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
        _tail_offset += OFFSET_SIZE;
        memcpy(&_buffer[_tail_offset], data_array.data(), len * sizeof(vec_inner_t<T>));
        _tail_offset += len * sizeof(vec_inner_t<T>);
        return data_array_offset;
    }

    template <typename T>
    typename std::enable_if<(is_serializable_offset_Type<vec_inner_t<T>>::value), SerializeOffset<Vector<vec_inner_t<T>>>>::type serialize_vector(T data_array)
    {
        SerializeOffset<Vector<vec_inner_t<T>>> data_array_offset;
        size_t len = data_array.size();
        _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

        make_buffer_adequate();
        data_array_offset.offset = _tail_offset;

        *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
        _tail_offset += OFFSET_SIZE;

        for (uint16_t i = 0; i < len; i++)
        {
            *reinterpret_cast<uint16_t*>(&_buffer[_tail_offset]) = data_array[i].offset - _tail_offset;
            _tail_offset += OFFSET_SIZE;
        }
        return data_array_offset;
    }
};




struct MonsterStruct {
SerializeOffset<String> name;
};




struct WeaponStruct {
SerializeOffset<String> name;
uint32_t damage;
};




struct AnyPower_enumStruct {
};


struct AnyPowerStruct {
};


struct PacketStruct {
int16_t id;
AnyPower_enum power_type;
SerializeOffset<void> power;
SerializeOffset<String> description;
uint32_t length;
SerializeOffset<Vector<uint16_t>> pos;
SerializeOffset<Monster> you;
SerializeOffset<Vector<Weapon>> arsenal;
};




inline SerializeOffset<Monster> serialize_monster(Serializer *const serializer,
 const SerializeOffset<String> name){
SerializeOffset<Monster> monster_offset;
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, MONSTER_ALIGNMENT);
serializer->make_buffer_adequate();
monster_offset.offset = serializer->_tail_offset;

*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + MONSTER_NAME_OFFSET])) = name.offset - (serializer->_tail_offset  +MONSTER_NAME_OFFSET);
serializer->_tail_offset += MONSTER_SIZE;
return monster_offset;
}

inline SerializeOffset<Weapon> serialize_weapon(Serializer *const serializer,
 const SerializeOffset<String> name,
 const uint32_t damage){
SerializeOffset<Weapon> weapon_offset;
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, WEAPON_ALIGNMENT);
serializer->make_buffer_adequate();
weapon_offset.offset = serializer->_tail_offset;

*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + WEAPON_NAME_OFFSET])) = name.offset - (serializer->_tail_offset  +WEAPON_NAME_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset  + WEAPON_DAMAGE_OFFSET])) = damage;
serializer->_tail_offset += WEAPON_SIZE;
return weapon_offset;
}

inline SerializeOffset<Packet> serialize_packet(Serializer *const serializer,
 const int16_t id,
 const AnyPower_enum power_type,
 const SerializeOffset<void> power,
 const SerializeOffset<String> description,
 const uint32_t length,
 const SerializeOffset<Vector<uint16_t>> pos,
 const SerializeOffset<Monster> you,
 const SerializeOffset<Vector<SerializeOffset<Weapon>>> arsenal){
SerializeOffset<Packet> packet_offset;
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);
serializer->make_buffer_adequate();
packet_offset.offset = serializer->_tail_offset;

*reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_ID_OFFSET])) = id;
*reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_POWER_TYPE_OFFSET])) = power_type;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_POWER_OFFSET])) = power.offset - (serializer->_tail_offset  +PACKET_POWER_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_DESCRIPTION_OFFSET])) = description.offset - (serializer->_tail_offset  +PACKET_DESCRIPTION_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_LENGTH_OFFSET])) = length;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_POS_OFFSET])) = pos.offset - (serializer->_tail_offset  +PACKET_POS_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_YOU_OFFSET])) = you.offset - (serializer->_tail_offset  +PACKET_YOU_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_ARSENAL_OFFSET])) = arsenal.offset - (serializer->_tail_offset  +PACKET_ARSENAL_OFFSET);
serializer->_tail_offset += PACKET_SIZE;
return packet_offset;
}

inline SerializeOffset<AnyPower> serialize_anypower(Serializer *const serializer){
SerializeOffset<AnyPower> anypower_offset;
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, ANYPOWER_ALIGNMENT);
serializer->make_buffer_adequate();
anypower_offset.offset = serializer->_tail_offset;

serializer->_tail_offset += ANYPOWER_SIZE;
return anypower_offset;
}



inline SerializeOffset<Vector<MonsterStruct>> serialize_vector_monster_struct(Serializer *const serializer, std::vector<MonsterStruct> data_array){
SerializeOffset<Vector<MonsterStruct>> data_array_offset;
uint16_t len = data_array.size();
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
serializer->make_buffer_adequate();
data_array_offset.offset = serializer->_tail_offset;
*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
serializer->_tail_offset += OFFSET_SIZE;serializer->_tail_offset += get_padding_size(serializer->_tail_offset, MONSTER_ALIGNMENT);for (uint16_t i = 0; i < len; i++){*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (MONSTER_SIZE * i) + MONSTER_NAME_OFFSET])) = data_array[i].name.offset - (serializer->_tail_offset  + (MONSTER_SIZE * i) +MONSTER_NAME_OFFSET);
serializer->_tail_offset += (MONSTER_SIZE * len);
}return data_array_offset;}

inline SerializeOffset<Vector<WeaponStruct>> serialize_vector_weapon_struct(Serializer *const serializer, std::vector<WeaponStruct> data_array){
SerializeOffset<Vector<WeaponStruct>> data_array_offset;
uint16_t len = data_array.size();
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
serializer->make_buffer_adequate();
data_array_offset.offset = serializer->_tail_offset;
*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
serializer->_tail_offset += OFFSET_SIZE;serializer->_tail_offset += get_padding_size(serializer->_tail_offset, WEAPON_ALIGNMENT);for (uint16_t i = 0; i < len; i++){*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (WEAPON_SIZE * i) + WEAPON_NAME_OFFSET])) = data_array[i].name.offset - (serializer->_tail_offset  + (WEAPON_SIZE * i) +WEAPON_NAME_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset  + (WEAPON_SIZE * i) + WEAPON_DAMAGE_OFFSET])) = data_array[i].damage;
serializer->_tail_offset += (WEAPON_SIZE * len);
}return data_array_offset;}

inline SerializeOffset<Vector<PacketStruct>> serialize_vector_packet_struct(Serializer *const serializer, std::vector<PacketStruct> data_array){
SerializeOffset<Vector<PacketStruct>> data_array_offset;
uint16_t len = data_array.size();
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
serializer->make_buffer_adequate();
data_array_offset.offset = serializer->_tail_offset;
*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
serializer->_tail_offset += OFFSET_SIZE;serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);for (uint16_t i = 0; i < len; i++){*reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_ID_OFFSET])) = data_array[i].id;
*reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_POWER_TYPE_OFFSET])) = data_array[i].power_type;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_POWER_OFFSET])) = data_array[i].power.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_POWER_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_DESCRIPTION_OFFSET])) = data_array[i].description.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_DESCRIPTION_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_LENGTH_OFFSET])) = data_array[i].length;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_POS_OFFSET])) = data_array[i].pos.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_POS_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_YOU_OFFSET])) = data_array[i].you.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_YOU_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_ARSENAL_OFFSET])) = data_array[i].arsenal.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_ARSENAL_OFFSET);
serializer->_tail_offset += (PACKET_SIZE * len);
}return data_array_offset;}

inline SerializeOffset<Vector<AnyPowerStruct>> serialize_vector_anypower_struct(Serializer *const serializer, std::vector<AnyPowerStruct> data_array){
SerializeOffset<Vector<AnyPowerStruct>> data_array_offset;
uint16_t len = data_array.size();
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
serializer->make_buffer_adequate();
data_array_offset.offset = serializer->_tail_offset;
*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
serializer->_tail_offset += OFFSET_SIZE;serializer->_tail_offset += get_padding_size(serializer->_tail_offset, ANYPOWER_ALIGNMENT);for (uint16_t i = 0; i < len; i++){serializer->_tail_offset += (ANYPOWER_SIZE * len);
}return data_array_offset;}



inline unsigned char *serialize_packet_root(Serializer *const serializer,
 const int16_t id,
 const AnyPower_enum power_type,
 const SerializeOffset<void> power,
 const SerializeOffset<String> description,
 const uint32_t length,
 const SerializeOffset<Vector<uint16_t>> pos,
 const SerializeOffset<Monster> you,
 const SerializeOffset<Vector<SerializeOffset<Weapon>>> arsenal){
uint16_t current_offset = OFFSET_SIZE * 2 + get_padding_size(OFFSET_SIZE * 2, PACKET_ALIGNMENT);


*reinterpret_cast<int16_t *>(&(serializer->_buffer[current_offset  + PACKET_ID_OFFSET])) = id;
*reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[current_offset  + PACKET_POWER_TYPE_OFFSET])) = power_type;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_POWER_OFFSET])) = power.offset - (current_offset  +PACKET_POWER_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_DESCRIPTION_OFFSET])) = description.offset - (current_offset  +PACKET_DESCRIPTION_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[current_offset  + PACKET_LENGTH_OFFSET])) = length;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_POS_OFFSET])) = pos.offset - (current_offset  +PACKET_POS_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_YOU_OFFSET])) = you.offset - (current_offset  +PACKET_YOU_OFFSET);
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_ARSENAL_OFFSET])) = arsenal.offset - (current_offset  +PACKET_ARSENAL_OFFSET);

*reinterpret_cast<uint16_t*>(&(serializer->_buffer[0])) = serializer->_tail_offset;

return serializer->_buffer;
}