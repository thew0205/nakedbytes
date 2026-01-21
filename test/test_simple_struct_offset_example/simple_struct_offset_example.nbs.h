#ifndef __SIMPLE_STRUCT_OFFSET_EXAMPLE_NAKEDBYTES_GENERATED_H
#define __SIMPLE_STRUCT_OFFSET_EXAMPLE_NAKEDBYTES_GENERATED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <type_traits>
#include <vector>

#define OFFSET_SIZE (8)
#define VERSION (7)

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

namespace nakedbytes
{
    NAKEDBYTES_FORCE_INLINE uint64_t get_padding_size(uint64_t offset, uint16_t alignment)
    {
        return static_cast<uint64_t>((alignment - (offset % alignment)) % alignment);
    }

    struct String
    {
        static constexpr uint64_t nakedbytes_sizeof = 8;

#define STRING_LENGTH_OFFSET 0
        NAKEDBYTES_FORCE_INLINE uint64_t length() const
        {
            const int64_t offset = STRING_LENGTH_OFFSET;
            return *reinterpret_cast<const uint64_t *>(&data_[offset]);
        }

#define STRING_VALUE_OFFSET 8
        NAKEDBYTES_FORCE_INLINE const char *c_str() const
        {
            const int64_t offset = STRING_VALUE_OFFSET;
            return reinterpret_cast<const char *>(&data_[offset]);
        }

    private:
        unsigned char data_[1];

        String() = delete;
        String(const String &other) = delete;
        String &operator=(const String &other) = delete;
    };

    template <typename T, typename Enable = void>
    struct Offset
    {
        static constexpr uint64_t nakedbytes_sizeof = 8;

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int64_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE const T *value_ptr() const
        {
            const int64_t offset = *reinterpret_cast<const int64_t *>(&data_[0]);
            return reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &value() const
        {
            const int64_t offset = *reinterpret_cast<const int64_t *>(&data_[0]);
            return *reinterpret_cast<const T *>(&data_[offset]);
        }

    private:
        unsigned char data_[1];

        Offset() = delete;
        Offset(const Offset &other) = delete;
        Offset &operator=(const Offset &other) = delete;
    };

    template <typename T>
    struct Offset<T, typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value)>::type>
    {
        static constexpr uint64_t nakedbytes_sizeof = sizeof(T);

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int64_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE const T *value_ptr() const
        {
            const int64_t offset = *reinterpret_cast<const int64_t *>(&data_[0]);
            return reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &value() const
        {
            const int64_t offset = *reinterpret_cast<const int64_t *>(&data_[0]);
            return *reinterpret_cast<const T *>(&data_[offset]);
        }

    private:
        unsigned char data_[1];

        Offset() = delete;
        Offset(const Offset &other) = delete;
        Offset &operator=(const Offset &other) = delete;
    };

    template <typename T>
    struct is_Offset_Type : std::false_type
    {
    };
    template <typename T>
    struct is_Offset_Type<Offset<T>> : std::true_type
    {
    };

    template <typename T, typename Enable = void>
    struct Vector
    {

        static constexpr uint64_t nakedbytes_sizeof = 8;

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int64_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE uint64_t size() const
        {
            const int64_t offset = *reinterpret_cast<const int64_t *>(&data_[0]);
            return *reinterpret_cast<const uint64_t *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &get(uint64_t index) const
        {
            const int64_t offset = static_cast<int64_t>(*reinterpret_cast<const int64_t *>(&data_[0])) + static_cast<int64_t>(OFFSET_SIZE) + static_cast<int64_t>(T::nakedbytes_sizeof) * static_cast<int64_t>(index);
            return *reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &operator[](uint64_t index) const
        {
            const int64_t offset = static_cast<int64_t>(*reinterpret_cast<const int64_t *>(&data_[0]) + OFFSET_SIZE + T::nakedbytes_sizeof * index);
            return *reinterpret_cast<const T *>(&data_[offset]);
        }

    public:
        struct Iterator
        {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T *;
            using reference = T &;

            Iterator(uint64_t index, const Vector<T> &vec) : index_(index), vec_{vec} {}

            value_type operator*() const { return vec_[index_]; }
            pointer operator->() { return vec_.get(index); }
            const Iterator operator++()
            {
                index_++;
                return Iterator(index_, vec_);
            }

            friend bool operator==(const Iterator &a, const Iterator &b) { return a.index_ == b.index_; };
            friend bool operator!=(const Iterator &a, const Iterator &b) { return a.index_ != b.index_; };

        private:
            uint64_t index_;
            const Vector<T> &vec_;
        };
        Iterator begin() const { return Iterator(0, *this); }
        Iterator end() const { return Iterator(size(), *this); }

    private:
        unsigned char data_[1];

        Vector() = delete;
        Vector(const Vector &other) = delete;
        Vector &operator=(const Vector &other) = delete;
    };

    template <typename T>
    struct Vector<T, typename std::enable_if<(std::is_floating_point<T>::value || std::is_integral<T>::value)>::type>
    {

        static constexpr uint64_t nakedbytes_sizeof = 8;

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int64_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE uint64_t size() const
        {
            const int64_t offset = *reinterpret_cast<const int64_t *>(&data_[0]);
            return *reinterpret_cast<const uint64_t *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &get(uint64_t index) const
        {
            const int64_t offset = static_cast<int64_t>(*reinterpret_cast<const int64_t *>(&data_[0])) + static_cast<int64_t>(OFFSET_SIZE) + static_cast<int64_t>(OFFSET_SIZE) * static_cast<int64_t>(index);
            return *reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &operator[](uint64_t index) const
        {
            const int64_t offset = static_cast<int64_t>(*reinterpret_cast<const int64_t *>(&data_[0])) + static_cast<int64_t>(OFFSET_SIZE) + static_cast<int64_t>(OFFSET_SIZE) * static_cast<int64_t>(index);
            return *reinterpret_cast<const T *>(&data_[offset]);
        }

    public:
        struct Iterator
        {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T *;
            using reference = T &;

            Iterator(uint64_t index, const Vector<T> &vec) : index_(index), vec_{vec} {}

            value_type operator*() const { return vec_[index_]; }
            pointer operator->() { return vec_.get(index); }
            const Iterator operator++()
            {
                index_++;
                return Iterator(index_, vec_);
            }

            friend bool operator==(const Iterator &a, const Iterator &b) { return a.index_ == b.index_; };
            friend bool operator!=(const Iterator &a, const Iterator &b) { return a.index_ != b.index_; };

        private:
            uint64_t index_;
            const Vector<T> &vec_;
        };
        Iterator begin() const { return Iterator(0, *this); }
        Iterator end() const { return Iterator(size(), *this); }

    private:
        unsigned char data_[1];

        Vector() = delete;
        Vector(const Vector &other) = delete;
        Vector &operator=(const Vector &other) = delete;
    };
}; // namespace nakedbytes

struct Weapon;
struct AnyPower;
struct Monster;
struct Packet;

enum AnyPower_enum : uint64_t
{

    AnyPower_enum_Monster,
    AnyPower_enum_Weapon,
    AnyPower_enum_int8,
};

inline const char *AnyPower_enum_to_string(AnyPower_enum value)
{
    switch (value)
    {
    case AnyPower_enum_Monster:
        return "AnyPower_enum_Monster";
    case AnyPower_enum_Weapon:
        return "AnyPower_enum_Weapon";
    case AnyPower_enum_int8:
        return "AnyPower_enum_int8";
    default:
        return NULL;
    }
}

struct Weapon
{

#define WEAPON_NAME_OFFSET 0
#define WEAPON_DAMAGE_OFFSET 8
#define WEAPON_PAD12_OFFSET 12
#define WEAPON_ALIGNMENT 8
#define WEAPON_SIZE 16
#define WEAPON_UNPADDED_SIZE 12

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *name() const
    {
        const int64_t offset = WEAPON_NAME_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE uint32_t damage() const
    {
        return *reinterpret_cast<const uint32_t *>(&data_[WEAPON_DAMAGE_OFFSET]);
    }

    static constexpr uint64_t nakedbytes_sizeof = 16;

private:
    Weapon() = delete;
    Weapon(const Weapon &) = delete;
    Weapon &operator=(const Weapon &) = delete;
    unsigned char data_[1];
};

struct Monster
{

#define MONSTER_NAME_OFFSET 0
#define MONSTER_ALIGNMENT 8
#define MONSTER_SIZE 8
#define MONSTER_UNPADDED_SIZE 8

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *name() const
    {
        const int64_t offset = MONSTER_NAME_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    static constexpr uint64_t nakedbytes_sizeof = 8;

private:
    Monster() = delete;
    Monster(const Monster &) = delete;
    Monster &operator=(const Monster &) = delete;
    unsigned char data_[1];
};

struct AnyPower
{

#define ANYPOWER_TYPE_OFFSET 0
#define ANYPOWER_DATA_OFFSET 8
#define ANYPOWER_ALIGNMENT 8
#define ANYPOWER_SIZE 8

    bool is_null() const
    {
        return (type() == 0) or (*reinterpret_cast<const int64_t *>(&data_[ANYPOWER_DATA_OFFSET]) == 0);
    }

    const unsigned char *raw_data() const
    {
        const int64_t offset = *reinterpret_cast<const int64_t *>(&data_[ANYPOWER_DATA_OFFSET]) + ANYPOWER_DATA_OFFSET;
        return reinterpret_cast<const unsigned char *>(&data_[offset]);
    }
    AnyPower_enum type() const
    {
        return *reinterpret_cast<const AnyPower_enum *>(&data_[ANYPOWER_TYPE_OFFSET]);
    }

    const ::nakedbytes::Offset<Monster> *data_as_Monster() const
    {
        return type() == AnyPower_enum_Monster ? reinterpret_cast<const ::nakedbytes::Offset<Monster> *>(&data_[ANYPOWER_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Weapon> *data_as_Weapon() const
    {
        return type() == AnyPower_enum_Weapon ? reinterpret_cast<const ::nakedbytes::Offset<Weapon> *>(&data_[ANYPOWER_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<int8_t> *data_as_int8() const
    {
        return type() == AnyPower_enum_int8 ? reinterpret_cast<const ::nakedbytes::Offset<int8_t> *>(&data_[ANYPOWER_DATA_OFFSET]) : nullptr;
    }

private:
    AnyPower() = delete;
    AnyPower(const AnyPower &) = delete;
    AnyPower &operator=(const AnyPower &) = delete;
    unsigned char data_[1];
};

struct Packet
{

#define PACKET_ID_OFFSET 0
#define PACKET_PAD2_OFFSET 2
#define PACKET_POWER_TYPE_OFFSET 8
#define PACKET_POWER_OFFSET 16
#define PACKET_DESCRIPTION_OFFSET 24
#define PACKET_LENGTH_OFFSET 32
#define PACKET_PAD36_OFFSET 36
#define PACKET_POS_OFFSET 40
#define PACKET_YOU_OFFSET 48
#define PACKET_ARSENAL_OFFSET 56
#define PACKET_ALIGNMENT 8
#define PACKET_SIZE 64
#define PACKET_UNPADDED_SIZE 64

    NAKEDBYTES_FORCE_INLINE int16_t id() const
    {
        return *reinterpret_cast<const int16_t *>(&data_[PACKET_ID_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE AnyPower_enum power_type() const
    {
        return *reinterpret_cast<const AnyPower_enum *>(&data_[PACKET_POWER_TYPE_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE const AnyPower *power() const
    {
        const int64_t offset = PACKET_POWER_TYPE_OFFSET;
        return reinterpret_cast<const AnyPower *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *description() const
    {
        const int64_t offset = PACKET_DESCRIPTION_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE uint32_t length() const
    {
        return *reinterpret_cast<const uint32_t *>(&data_[PACKET_LENGTH_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Vector<uint16_t> *pos() const
    {
        const int64_t offset = PACKET_POS_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Vector<uint16_t> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<Monster> *you() const
    {
        const int64_t offset = PACKET_YOU_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<Monster> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Vector<::nakedbytes::Offset<Weapon>> *arsenal() const
    {
        const int64_t offset = PACKET_ARSENAL_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Vector<::nakedbytes::Offset<Weapon>> *>(&data_[offset]);
    }

    static constexpr uint64_t nakedbytes_sizeof = 64;

private:
    Packet() = delete;
    Packet(const Packet &) = delete;
    Packet &operator=(const Packet &) = delete;
    unsigned char data_[1];
};

const Packet *GetRootPacket(const unsigned char *const buffer)
{
    return reinterpret_cast<const Packet *>(&buffer[2 * OFFSET_SIZE + ::nakedbytes::get_padding_size((2 * OFFSET_SIZE), PACKET_ALIGNMENT)]);
}

namespace nakedbytes
{
    template <typename T>
    struct SerializeOffset
    {
        // Offset relative to the start of the buffer
        uint64_t offset = 0;

        template <typename U = void>
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

        unsigned char *_buffer = nullptr;
        uint64_t _buffer_size = 0;
        // uint64_t _current_offset = 0;
        uint64_t _tail_offset = 0;

        void init(uint64_t buffer_size, const uint16_t root_type_size, uint16_t root_type_alignment)
        {
            _buffer = static_cast<unsigned char *>(malloc(buffer_size));
            _buffer_size = buffer_size;
            *reinterpret_cast<uint64_t *>(&_buffer[OFFSET_SIZE]) = VERSION;

            _tail_offset = static_cast<uint16_t>(static_cast<uint64_t>(get_padding_size(OFFSET_SIZE * 2, root_type_alignment)) + static_cast<uint64_t>(OFFSET_SIZE) * 2 + static_cast<uint64_t>(root_type_size));
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
                uint64_t len = static_cast<uint64_t>(strlen(str));
                _tail_offset += static_cast<uint64_t>(get_padding_size(_tail_offset, OFFSET_SIZE));

                make_buffer_adequate();
                str_offset.offset = _tail_offset;

                *reinterpret_cast<uint64_t *>(&_buffer[_tail_offset]) = len;
                _tail_offset += OFFSET_SIZE;
                memcpy(&_buffer[_tail_offset], str, len);
                *reinterpret_cast<unsigned char *>(&(((unsigned char *)_buffer)[_tail_offset + len])) = 0;
                _tail_offset += static_cast<uint64_t>(len + 1);
            }
            return str_offset;
        }

        template <typename T>
        typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_enum<T>::value), SerializeOffset<T>>::type serialize_primitive(T data)
        {
            SerializeOffset<T> data_offset;
            _tail_offset += static_cast<uint64_t>(get_padding_size(_tail_offset, sizeof(T)));

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
            uint64_t len = static_cast<uint64_t>(data_array.size());
            _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

            make_buffer_adequate();
            data_array_offset.offset = _tail_offset;

            *reinterpret_cast<uint64_t *>(&_buffer[_tail_offset]) = len;
            _tail_offset += OFFSET_SIZE;
            memcpy(&_buffer[_tail_offset], data_array.data(), len * sizeof(vec_inner_t<T>));
            _tail_offset += len * sizeof(vec_inner_t<T>);
            return data_array_offset;
        }

        template <typename T>
        typename std::enable_if<(is_serializable_offset_Type<vec_inner_t<T>>::value), SerializeOffset<Vector<vec_inner_t<T>>>>::type serialize_vector(T data_array)
        {
            SerializeOffset<Vector<vec_inner_t<T>>> data_array_offset;
            uint64_t len = static_cast<uint64_t>(data_array.size());
            _tail_offset += get_padding_size(_tail_offset, OFFSET_SIZE);

            make_buffer_adequate();
            data_array_offset.offset = _tail_offset;

            *reinterpret_cast<uint64_t *>(&_buffer[_tail_offset]) = len;
            _tail_offset += OFFSET_SIZE;

            for (uint64_t i = 0; i < len; i++)
            {
                *reinterpret_cast<uint64_t *>(&_buffer[_tail_offset]) = data_array[i].offset - _tail_offset;
                _tail_offset += OFFSET_SIZE;
            }
            return data_array_offset;
        }

        void deinit()
        {
            if (_buffer != nullptr)
            {
                free(_buffer);
                _buffer = nullptr;
                _buffer_size = 0;
                _tail_offset = 0;
            }
        }

        ~Serializer()
        {
            deinit();
        }

        const unsigned char *get_buffer() const
        {
            return _buffer;
        }

        size_t get_size() const
        {
            return _tail_offset;
        }
    };
}; // namespace nakedbytes

struct WeaponStruct
{
    ::nakedbytes::SerializeOffset<::nakedbytes::String> name;
    uint32_t damage;
};

struct MonsterStruct
{
    ::nakedbytes::SerializeOffset<::nakedbytes::String> name;
};

struct AnyPower_enumStruct
{
};

struct AnyPowerStruct
{
};

struct PacketStruct
{
    int16_t id;
    AnyPower_enum power_type;
    ::nakedbytes::SerializeOffset<void> power;
    ::nakedbytes::SerializeOffset<::nakedbytes::String> description;
    uint32_t length;
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<uint16_t>> pos;
    ::nakedbytes::SerializeOffset<Monster> you;
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Weapon>> arsenal;
};

inline ::nakedbytes::SerializeOffset<Weapon> serialize_weapon(::nakedbytes::Serializer *const serializer,
                                                              const ::nakedbytes::SerializeOffset<::nakedbytes::String> name,
                                                              const uint32_t damage)
{
    ::nakedbytes::SerializeOffset<Weapon> weapon_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, WEAPON_ALIGNMENT);
    serializer->make_buffer_adequate();
    weapon_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + WEAPON_NAME_OFFSET])) = static_cast<int64_t>(name.offset - (serializer->_tail_offset + WEAPON_NAME_OFFSET));
    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + WEAPON_DAMAGE_OFFSET])) = static_cast<uint32_t>(damage);
    serializer->_tail_offset += WEAPON_SIZE;
    return weapon_offset;
}

inline ::nakedbytes::SerializeOffset<AnyPower> serialize_anypower(::nakedbytes::Serializer *const serializer)
{
    ::nakedbytes::SerializeOffset<AnyPower> anypower_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ANYPOWER_ALIGNMENT);
    serializer->make_buffer_adequate();
    anypower_offset.offset = serializer->_tail_offset;

    serializer->_tail_offset += ANYPOWER_SIZE;
    return anypower_offset;
}

inline ::nakedbytes::SerializeOffset<Monster> serialize_monster(::nakedbytes::Serializer *const serializer,
                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> name)
{
    ::nakedbytes::SerializeOffset<Monster> monster_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, MONSTER_ALIGNMENT);
    serializer->make_buffer_adequate();
    monster_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + MONSTER_NAME_OFFSET])) = static_cast<int64_t>(name.offset - (serializer->_tail_offset + MONSTER_NAME_OFFSET));
    serializer->_tail_offset += MONSTER_SIZE;
    return monster_offset;
}

inline ::nakedbytes::SerializeOffset<Packet> serialize_packet(::nakedbytes::Serializer *const serializer,
                                                              const int16_t id,
                                                              const AnyPower_enum power_type,
                                                              const ::nakedbytes::SerializeOffset<void> power,
                                                              const ::nakedbytes::SerializeOffset<::nakedbytes::String> description,
                                                              const uint32_t length,
                                                              const ::nakedbytes::SerializeOffset<::nakedbytes::Vector<uint16_t>> pos,
                                                              const ::nakedbytes::SerializeOffset<Monster> you,
                                                              const ::nakedbytes::SerializeOffset<::nakedbytes::Vector<::nakedbytes::SerializeOffset<Weapon>>> arsenal)
{
    ::nakedbytes::SerializeOffset<Packet> packet_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);
    serializer->make_buffer_adequate();
    packet_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_ID_OFFSET])) = static_cast<int16_t>(id);
    *reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_POWER_TYPE_OFFSET])) = static_cast<AnyPower_enum>(power_type);
    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_POWER_OFFSET])) = static_cast<int64_t>(power.offset - (serializer->_tail_offset + PACKET_POWER_OFFSET));
    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_DESCRIPTION_OFFSET])) = static_cast<int64_t>(description.offset - (serializer->_tail_offset + PACKET_DESCRIPTION_OFFSET));
    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_LENGTH_OFFSET])) = static_cast<uint32_t>(length);
    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_POS_OFFSET])) = static_cast<int64_t>(pos.offset - (serializer->_tail_offset + PACKET_POS_OFFSET));
    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_YOU_OFFSET])) = static_cast<int64_t>(you.offset - (serializer->_tail_offset + PACKET_YOU_OFFSET));
    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_ARSENAL_OFFSET])) = static_cast<int64_t>(arsenal.offset - (serializer->_tail_offset + PACKET_ARSENAL_OFFSET));
    serializer->_tail_offset += PACKET_SIZE;
    return packet_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<WeaponStruct>> serialize_vector_weapon_struct(::nakedbytes::Serializer *const serializer, std::vector<WeaponStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<WeaponStruct>> data_array_offset;
    uint64_t len = static_cast<uint64_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint64_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint64_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, WEAPON_ALIGNMENT);
    for (uint64_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (WEAPON_SIZE * i) + WEAPON_NAME_OFFSET])) = static_cast<int64_t>(data_array[i].name.offset - (serializer->_tail_offset + (WEAPON_SIZE * i) + WEAPON_NAME_OFFSET));
        *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + (WEAPON_SIZE * i) + WEAPON_DAMAGE_OFFSET])) = static_cast<uint32_t>(data_array[i].damage);
        serializer->_tail_offset += static_cast<uint64_t>(WEAPON_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<AnyPowerStruct>> serialize_vector_anypower_struct(::nakedbytes::Serializer *const serializer, std::vector<AnyPowerStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<AnyPowerStruct>> data_array_offset;
    uint64_t len = static_cast<uint64_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint64_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint64_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ANYPOWER_ALIGNMENT);
    for (uint64_t i = 0; i < len; i++)
    {
        serializer->_tail_offset += static_cast<uint64_t>(ANYPOWER_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<MonsterStruct>> serialize_vector_monster_struct(::nakedbytes::Serializer *const serializer, std::vector<MonsterStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<MonsterStruct>> data_array_offset;
    uint64_t len = static_cast<uint64_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint64_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint64_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, MONSTER_ALIGNMENT);
    for (uint64_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (MONSTER_SIZE * i) + MONSTER_NAME_OFFSET])) = static_cast<int64_t>(data_array[i].name.offset - (serializer->_tail_offset + (MONSTER_SIZE * i) + MONSTER_NAME_OFFSET));
        serializer->_tail_offset += static_cast<uint64_t>(MONSTER_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<PacketStruct>> serialize_vector_packet_struct(::nakedbytes::Serializer *const serializer, std::vector<PacketStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<PacketStruct>> data_array_offset;
    uint64_t len = static_cast<uint64_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint64_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint64_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);
    for (uint64_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_ID_OFFSET])) = static_cast<int16_t>(data_array[i].id);
        *reinterpret_cast<AnyPower_enum *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_POWER_TYPE_OFFSET])) = static_cast<AnyPower_enum>(data_array[i].power_type);
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_POWER_OFFSET])) = static_cast<int64_t>(data_array[i].power.offset - (serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_POWER_OFFSET));
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_DESCRIPTION_OFFSET])) = static_cast<int64_t>(data_array[i].description.offset - (serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_DESCRIPTION_OFFSET));
        *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_LENGTH_OFFSET])) = static_cast<uint32_t>(data_array[i].length);
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_POS_OFFSET])) = static_cast<int64_t>(data_array[i].pos.offset - (serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_POS_OFFSET));
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_YOU_OFFSET])) = static_cast<int64_t>(data_array[i].you.offset - (serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_YOU_OFFSET));
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_ARSENAL_OFFSET])) = static_cast<int64_t>(data_array[i].arsenal.offset - (serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_ARSENAL_OFFSET));
        serializer->_tail_offset += static_cast<uint64_t>(PACKET_SIZE * len);
    }
    return data_array_offset;
}

struct PacketSerializer : public ::nakedbytes::Serializer
{
    void init(uint64_t buffer_size)
    {
        ::nakedbytes::Serializer::init(buffer_size, PACKET_SIZE, PACKET_ALIGNMENT);
    }

    inline uint64_t serialize_root(
        const int16_t id,
        const AnyPower_enum power_type,
        const ::nakedbytes::SerializeOffset<void> power,
        const ::nakedbytes::SerializeOffset<::nakedbytes::String> description,
        const uint32_t length,
        const ::nakedbytes::SerializeOffset<::nakedbytes::Vector<uint16_t>> pos,
        const ::nakedbytes::SerializeOffset<Monster> you,
        const ::nakedbytes::SerializeOffset<::nakedbytes::Vector<::nakedbytes::SerializeOffset<Weapon>>> arsenal)
    {
        uint64_t current_offset = static_cast<uint64_t>(OFFSET_SIZE * 2 + ::nakedbytes::get_padding_size(OFFSET_SIZE * 2, PACKET_ALIGNMENT));
        *reinterpret_cast<int16_t *>(&(this->_buffer[current_offset + PACKET_ID_OFFSET])) = static_cast<int16_t>(id);
        *reinterpret_cast<AnyPower_enum *>(&(this->_buffer[current_offset + PACKET_POWER_TYPE_OFFSET])) = static_cast<AnyPower_enum>(power_type);
        *reinterpret_cast<int64_t *>(&(this->_buffer[current_offset + PACKET_POWER_OFFSET])) = static_cast<int64_t>(power.offset - (current_offset + PACKET_POWER_OFFSET));
        *reinterpret_cast<int64_t *>(&(this->_buffer[current_offset + PACKET_DESCRIPTION_OFFSET])) = static_cast<int64_t>(description.offset - (current_offset + PACKET_DESCRIPTION_OFFSET));
        *reinterpret_cast<uint32_t *>(&(this->_buffer[current_offset + PACKET_LENGTH_OFFSET])) = static_cast<uint32_t>(length);
        *reinterpret_cast<int64_t *>(&(this->_buffer[current_offset + PACKET_POS_OFFSET])) = static_cast<int64_t>(pos.offset - (current_offset + PACKET_POS_OFFSET));
        *reinterpret_cast<int64_t *>(&(this->_buffer[current_offset + PACKET_YOU_OFFSET])) = static_cast<int64_t>(you.offset - (current_offset + PACKET_YOU_OFFSET));
        *reinterpret_cast<int64_t *>(&(this->_buffer[current_offset + PACKET_ARSENAL_OFFSET])) = static_cast<int64_t>(arsenal.offset - (current_offset + PACKET_ARSENAL_OFFSET));

        *reinterpret_cast<uint64_t *>(&(this->_buffer[0])) = this->_tail_offset;

        return this->_tail_offset;
    }
};

#endif //__SIMPLE_STRUCT_OFFSET_EXAMPLE_NAKEDBYTES_GENERATED_H