
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <type_traits>
#include <vector>

#define OFFSET_SIZE 2
#if defined(__GNUC__) || defined(__clang__)
#define NAKEDBYTES_INLINE inline
#else
#define NAKEDBYTES_INLINE inline
#endif

#if defined(__GNUC__) || defined(__clang__)
#define NAKEDBYTES_FORCE_INLINE inline __attribute__((always_inline))
#else
#define NAKEDBYTES_FORCE_INLINE inline
#endif



struct AnyPower; 
struct Packet; 
struct Monster; 
struct Weapon; 



struct String
{
#define STRING_LENGTH_OFFSET 0
    NAKEDBYTES_FORCE_INLINE const uint16_t length() const
    {
        const int16_t offset = STRING_LENGTH_OFFSET;
        return *reinterpret_cast<const uint16_t *>(&data_[offset]);
    }

#define STRING_VALUE_OFFSET 2
    NAKEDBYTES_FORCE_INLINE const char *c_str() const
    {
        const int16_t offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data_[offset]);
    }
    
private:
    
    unsigned char data_[1];

    String() = delete;
    String (const String &other) = delete;
    String &operator=(const String &other) = delete;
    
};

template<typename T, typename Enable = void>
struct Offset
{
    static constexpr size_t nakedbytes_sizeof = 2;

    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[0]) == 0;
    }

    NAKEDBYTES_FORCE_INLINE const T* value_ptr() const
    {
        const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
        return reinterpret_cast<const T*>(&data_[offset]);
    }
    
    NAKEDBYTES_FORCE_INLINE const T& value() const
    {
        const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }
    
private:

    unsigned char data_[1];

    Offset() = delete;
    Offset (const Offset &other) = delete;
    Offset &operator=(const Offset &other) = delete;
};

template<typename T>
struct Offset<T, typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value)>::type>
{
    static constexpr size_t nakedbytes_sizeof = sizeof(T);
    
    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[0]) == 0;
    }

    NAKEDBYTES_FORCE_INLINE const T* value_ptr() const
    {
        const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
        return reinterpret_cast<const T*>(&data_[offset]);
    }
    
    NAKEDBYTES_FORCE_INLINE const T& value() const
    {
        const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
        return *reinterpret_cast<const T*>(&data_[offset]);
    }
    
private:

    unsigned char data_[1];

    Offset() = delete;
    Offset (const Offset &other) = delete;
    Offset &operator=(const Offset &other) = delete;
};

template<typename T> struct is_Offset_Type : std::false_type {};
template<typename T>
struct is_Offset_Type<Offset<T>> : std::true_type {};


template<typename T, typename Enable = void>
struct Vector
{

    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[0]) == 0;
    }
    
    NAKEDBYTES_FORCE_INLINE uint16_t size() const
    {
        const int16_t offset =  *reinterpret_cast<const uint16_t *>(&data_[0]);
        return *reinterpret_cast<const uint16_t *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const T& get(size_t index) const
    {
        const int16_t offset =  *reinterpret_cast<const uint16_t *>(&data_[0]) + OFFSET_SIZE + T::nakedbytes_sizeof * index;
        return *reinterpret_cast<const T*>(&data_[offset]);
    }
    
    NAKEDBYTES_FORCE_INLINE const T& operator[](size_t index) const {
        const int16_t offset =  *reinterpret_cast<const uint16_t *>(&data_[0]) + OFFSET_SIZE + T::nakedbytes_sizeof * index;
        return *reinterpret_cast<const T*>(&data_[offset]);
    }

    
private:

    unsigned char data_[1];

    Vector() = delete;
    Vector (const Vector &other) = delete;
    Vector &operator=(const Vector &other) = delete;
};

template<typename T>
struct Vector<T, typename std::enable_if<(std::is_floating_point<T>::value || std::is_integral<T>::value)>::type>
{

    NAKEDBYTES_FORCE_INLINE bool is_null() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[0]) == 0;
    }
    
    NAKEDBYTES_FORCE_INLINE uint16_t size() const
    {
        int16_t offset =  *reinterpret_cast<const uint16_t *>(&data_[0]);
        return *reinterpret_cast<const uint16_t *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const T& get(size_t index) const
    {
        const int16_t offset =  *reinterpret_cast<const uint16_t *>(&data_[0]) + OFFSET_SIZE + OFFSET_SIZE * index;
        return *reinterpret_cast<const T*>(&data_[offset]);
    }
    
    NAKEDBYTES_FORCE_INLINE const T& operator[](size_t index) const {
        const int16_t offset =  *reinterpret_cast<const uint16_t *>(&data_[0]) + OFFSET_SIZE + OFFSET_SIZE * index;
        return *reinterpret_cast<const T*>(&data_[offset]);
    }


private:

    unsigned char data_[1];

    Vector() = delete;
    Vector (const Vector &other) = delete;
    Vector &operator=(const Vector &other) = delete;
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




struct Monster  {

#define MONSTER_NAME_OFFSET 0
#define MONSTER_ALIGNMENT 2
#define MONSTER_SIZE 2


NAKEDBYTES_FORCE_INLINE const Offset<String>& name() const {
const int16_t offset = MONSTER_NAME_OFFSET ;
return *reinterpret_cast<const Offset<String>*>(&data_[offset]);
}

static constexpr size_t nakedbytes_sizeof = 2;

private:
Monster() =delete;
Monster(const Monster &) =delete;
Monster& operator=(const Monster &) =delete;
unsigned char data_[1];

};





struct Weapon  {

#define WEAPON_NAME_OFFSET 0
#define WEAPON_PAD2_OFFSET 2
#define WEAPON_DAMAGE_OFFSET 4
#define WEAPON_ALIGNMENT 4
#define WEAPON_SIZE 8


NAKEDBYTES_FORCE_INLINE const Offset<String>& name() const {
const int16_t offset = WEAPON_NAME_OFFSET ;
return *reinterpret_cast<const Offset<String>*>(&data_[offset]);
}

NAKEDBYTES_FORCE_INLINE const uint32_t damage() const {
return *reinterpret_cast<const uint32_t*>(&data_[WEAPON_DAMAGE_OFFSET ]);
}

static constexpr size_t nakedbytes_sizeof = 8;

private:
Weapon() =delete;
Weapon(const Weapon &) =delete;
Weapon& operator=(const Weapon &) =delete;
unsigned char data_[1];

};





struct AnyPower{

#define ANYPOWER_TYPE_OFFSET 0
#define ANYPOWER_DATA_OFFSET 2
#define ANYPOWER_ALIGNMENT 2
#define ANYPOWER_SIZE 2


bool is_null() const {
return (type() == 0) or (*reinterpret_cast<const uint16_t *>(&data_[ANYPOWER_DATA_OFFSET]) == 0);
}

const unsigned char *raw_data() const {const int16_t offset = *reinterpret_cast<const uint16_t *>(&data_[ANYPOWER_DATA_OFFSET]) + ANYPOWER_DATA_OFFSET;
return reinterpret_cast<const unsigned char *>(&data_[offset]);
}
AnyPower_enum type() const {
return *reinterpret_cast<const AnyPower_enum *>(&data_[ANYPOWER_TYPE_OFFSET]);
}

const Offset<Monster>* data_as_Monster() const {
return type() == AnyPower_enum_Monster ? reinterpret_cast<const Offset<Monster>*>(&data_[ANYPOWER_DATA_OFFSET]) : nullptr;
}

const Offset<Weapon>* data_as_Weapon() const {
return type() == AnyPower_enum_Weapon ? reinterpret_cast<const Offset<Weapon>*>(&data_[ANYPOWER_DATA_OFFSET]) : nullptr;
}

private:
AnyPower() =delete;
AnyPower(const AnyPower &) =delete;
AnyPower& operator=(const AnyPower &) =delete;
unsigned char data_[1];



};





struct Packet  {

#define PACKET_ID_OFFSET 0
#define PACKET_DESCRIPTION_OFFSET 2
#define PACKET_POWER_TYPE_OFFSET 4
#define PACKET_POWER_OFFSET 6
#define PACKET_LENGTH_OFFSET 8
#define PACKET_YOU_OFFSET 12
#define PACKET_PAD14_OFFSET 14
#define PACKET_ALIGNMENT 4
#define PACKET_SIZE 16


NAKEDBYTES_FORCE_INLINE const int16_t id() const {
return *reinterpret_cast<const int16_t*>(&data_[PACKET_ID_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const Offset<String>& description() const {
const int16_t offset = PACKET_DESCRIPTION_OFFSET ;
return *reinterpret_cast<const Offset<String>*>(&data_[offset]);
}

NAKEDBYTES_FORCE_INLINE const AnyPower_enum power_type() const {
return *reinterpret_cast<const AnyPower_enum*>(&data_[PACKET_POWER_TYPE_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const AnyPower& power() const {
const int16_t offset = PACKET_POWER_OFFSET - 2 ;
return *reinterpret_cast<const AnyPower*>(&data_[offset]);
}

NAKEDBYTES_FORCE_INLINE const uint32_t length() const {
return *reinterpret_cast<const uint32_t*>(&data_[PACKET_LENGTH_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const Offset<Monster>& you() const {const int16_t offset =PACKET_YOU_OFFSET ;return *reinterpret_cast<const Offset<Monster>*>(&data_[offset]);}

static constexpr size_t nakedbytes_sizeof = 16;

private:
Packet() =delete;
Packet(const Packet &) =delete;
Packet& operator=(const Packet &) =delete;
unsigned char data_[1];

};











struct PacketRoot  {

#define PACKET_ID_OFFSET 0
#define PACKET_DESCRIPTION_OFFSET 2
#define PACKET_POWER_TYPE_OFFSET 4
#define PACKET_POWER_OFFSET 6
#define PACKET_LENGTH_OFFSET 8
#define PACKET_YOU_OFFSET 12
#define PACKET_PAD14_OFFSET 14
#define PACKET_ALIGNMENT 4
#define PACKET_SIZE 16


NAKEDBYTES_FORCE_INLINE const int16_t id() const {
return *reinterpret_cast<const int16_t*>(&data_[PACKET_ID_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const Offset<String>& description() const {
const int16_t offset = PACKET_DESCRIPTION_OFFSET + 2* OFFSET_SIZE;
return *reinterpret_cast<const Offset<String>*>(&data_[offset]);
}

NAKEDBYTES_FORCE_INLINE const AnyPower_enum power_type() const {
return *reinterpret_cast<const AnyPower_enum*>(&data_[PACKET_POWER_TYPE_OFFSET + 2 * OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const AnyPower& power() const {
const int16_t offset = PACKET_POWER_OFFSET - 2 + 2* OFFSET_SIZE;
return *reinterpret_cast<const AnyPower*>(&data_[offset]);
}

NAKEDBYTES_FORCE_INLINE const uint32_t length() const {
return *reinterpret_cast<const uint32_t*>(&data_[PACKET_LENGTH_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const Offset<Monster>& you() const {const int16_t offset =PACKET_YOU_OFFSET + 2* OFFSET_SIZE;return *reinterpret_cast<const Offset<Monster>*>(&data_[offset]);}

static constexpr size_t nakedbytes_sizeof = 16;

private:
PacketRoot() =delete;
PacketRoot(const PacketRoot &) =delete;
PacketRoot& operator=(const PacketRoot &) =delete;
unsigned char data_[1];

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




struct AnyPower_enumStruct {
};


struct AnyPowerStruct {
};


struct MonsterStruct {
SerializeOffset<String> name;
};


struct PacketStruct {
int16_t id;
SerializeOffset<String> description;
AnyPower_enum power_type;
SerializeOffset<void> power;
uint32_t length;
SerializeOffset<Monster> you;
};






struct WeaponStruct {
SerializeOffset<String> name;
uint32_t damage;
};




inline SerializeOffset<AnyPower> serialize_anypower(Serializer *const serializer){
SerializeOffset<AnyPower> anypower_offset;
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, ANYPOWER_ALIGNMENT);
serializer->make_buffer_adequate();
anypower_offset.offset = serializer->_tail_offset;

serializer->_tail_offset += ANYPOWER_SIZE;
return anypower_offset;
}

inline SerializeOffset<Packet> serialize_packet(Serializer *const serializer,
 const int16_t id,
 const SerializeOffset<String> description,
 const AnyPower_enum power_type,
 const SerializeOffset<void> power,
 const uint32_t length,
 const SerializeOffset<Monster> you){
SerializeOffset<Packet> packet_offset;
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);
serializer->make_buffer_adequate();
packet_offset.offset = serializer->_tail_offset;

*reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_ID_OFFSET])) = id;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_DESCRIPTION_OFFSET])) = description.offset - (serializer->_tail_offset  +PACKET_DESCRIPTION_OFFSET);
*reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_POWER_TYPE_OFFSET])) = power_type;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_POWER_OFFSET])) = power.offset - (serializer->_tail_offset  +PACKET_POWER_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_LENGTH_OFFSET])) = length;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PACKET_YOU_OFFSET])) = you.offset - (serializer->_tail_offset  +PACKET_YOU_OFFSET);
serializer->_tail_offset += PACKET_SIZE;
return packet_offset;
}

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



inline SerializeOffset<Vector<AnyPowerStruct>> serialize_vector_anypower_struct(Serializer *const serializer, std::vector<AnyPowerStruct> data_array){
SerializeOffset<Vector<AnyPowerStruct>> data_array_offset;
uint16_t len = data_array.size();
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
serializer->make_buffer_adequate();
data_array_offset.offset = serializer->_tail_offset;
*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
serializer->_tail_offset += OFFSET_SIZE;serializer->_tail_offset += get_padding_size(serializer->_tail_offset, ANYPOWER_ALIGNMENT);for (uint16_t i = 0; i < len; i++){serializer->_tail_offset += (ANYPOWER_SIZE * len);
}return data_array_offset;}

inline SerializeOffset<Vector<PacketStruct>> serialize_vector_packet_struct(Serializer *const serializer, std::vector<PacketStruct> data_array){
SerializeOffset<Vector<PacketStruct>> data_array_offset;
uint16_t len = data_array.size();
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
serializer->make_buffer_adequate();
data_array_offset.offset = serializer->_tail_offset;
*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
serializer->_tail_offset += OFFSET_SIZE;serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);for (uint16_t i = 0; i < len; i++){*reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_ID_OFFSET])) = data_array[i].id;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_DESCRIPTION_OFFSET])) = data_array[i].description.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_DESCRIPTION_OFFSET);
*reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_POWER_TYPE_OFFSET])) = data_array[i].power_type;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_POWER_OFFSET])) = data_array[i].power.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_POWER_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_LENGTH_OFFSET])) = data_array[i].length;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PACKET_SIZE * i) + PACKET_YOU_OFFSET])) = data_array[i].you.offset - (serializer->_tail_offset  + (PACKET_SIZE * i) +PACKET_YOU_OFFSET);
serializer->_tail_offset += (PACKET_SIZE * len);
}return data_array_offset;}

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



inline unsigned char *serialize_packet_root(Serializer *const serializer,
 const int16_t id,
 const SerializeOffset<String> description,
 const AnyPower_enum power_type,
 const SerializeOffset<void> power,
 const uint32_t length,
 const SerializeOffset<Monster> you){
uint16_t current_offset = OFFSET_SIZE * 2 + get_padding_size(OFFSET_SIZE * 2, PACKET_ALIGNMENT);


*reinterpret_cast<int16_t *>(&(serializer->_buffer[current_offset  + PACKET_ID_OFFSET])) = id;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_DESCRIPTION_OFFSET])) = description.offset - (current_offset  +PACKET_DESCRIPTION_OFFSET);
*reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[current_offset  + PACKET_POWER_TYPE_OFFSET])) = power_type;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_POWER_OFFSET])) = power.offset - (current_offset  +PACKET_POWER_OFFSET);
*reinterpret_cast<uint32_t *>(&(serializer->_buffer[current_offset  + PACKET_LENGTH_OFFSET])) = length;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PACKET_YOU_OFFSET])) = you.offset - (current_offset  +PACKET_YOU_OFFSET);

*reinterpret_cast<uint16_t*>(&(serializer->_buffer[0])) = serializer->_tail_offset;

return serializer->_buffer;
}