
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <type_traits>
#include <vector>

#define OFFSET_SIZE 2

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
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *c_str() const
    {
        uint16_t offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }
};

template <typename T, typename Enable = void>
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

template <typename T>
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

template <typename T>
struct is_Offset_Type : std::false_type
{
};
template <typename T>
struct is_Offset_Type<Offset<T>> : std::true_type
{
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

template <typename T, typename Enable = void>
struct Vector
{
    unsigned char *data;

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }

    uint16_t size() const
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index) const
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + T::nakedbytes_sizeof * index;

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};

template <typename T>
struct Vector<T, typename std::enable_if<(std::is_floating_point<T>::value || std::is_integral<T>::value)>::type>
{
    unsigned char *data;

    bool is_null() const
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }

    uint16_t size() const
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index) const
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + OFFSET_SIZE * index;

        return static_cast<T>(data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};

struct Packet
{

    static constexpr size_t nakedbytes_sizeof = 8;

    unsigned char *data_;

    Packet(unsigned char *data) : data_(data) {}

#define PACKET_ID_OFFSET 0
#define PACKET_PAD2_OFFSET 2
#define PACKET_LENGTH_OFFSET 4
#define PACKET_ALIGNMENT 4
#define PACKET_SIZE 8

    int16_t id() const
    {
        return *reinterpret_cast<int16_t *>(&data_[PACKET_ID_OFFSET]);
    }

    uint32_t length() const
    {
        return *reinterpret_cast<uint32_t *>(&data_[PACKET_LENGTH_OFFSET]);
    }
};

struct PacketRoot
{

    unsigned char data_[1];

    PacketRoot()  {}

#define PACKET_ID_OFFSET 0
#define PACKET_PAD2_OFFSET 2
#define PACKET_LENGTH_OFFSET 4
#define PACKET_ALIGNMENT 4
#define PACKET_SIZE 8

    int16_t id() const
    {
        auto a = &data_[PACKET_ID_OFFSET + 2 * OFFSET_SIZE];
        return *reinterpret_cast<const int16_t *>(a);
    }

    uint32_t length() const
    {
        return *reinterpret_cast<const uint32_t *>(&data_[PACKET_LENGTH_OFFSET + 2 * OFFSET_SIZE]);
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
            *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = data_array[i].offset - _tail_offset;
            _tail_offset += OFFSET_SIZE;
        }
        return data_array_offset;
    }
};

struct PacketStruct
{
    int16_t id;
    uint32_t length;
};

inline SerializeOffset<Packet> serialize_packet(Serializer *const serializer,
                                                const int16_t id,
                                                const uint32_t length)
{
    SerializeOffset<Packet> packet_offset;
    serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);
    serializer->make_buffer_adequate();
    packet_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_ID_OFFSET])) = id;
    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + PACKET_LENGTH_OFFSET])) = length;
    serializer->_tail_offset += PACKET_SIZE;
    return packet_offset;
}

inline SerializeOffset<Vector<PacketStruct>> serialize_vector_packet_struct(Serializer *const serializer, std::vector<PacketStruct> data_array)
{
    SerializeOffset<Vector<PacketStruct>> data_array_offset;
    uint16_t len = data_array.size();
    serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PACKET_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_ID_OFFSET])) = data_array[i].id;
        *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + (PACKET_SIZE * i) + PACKET_LENGTH_OFFSET])) = data_array[i].length;
        serializer->_tail_offset += (PACKET_SIZE * len);
    }
    return data_array_offset;
}

inline unsigned char *serialize_packet_root(Serializer *const serializer,
                                            const int16_t id,
                                            const uint32_t length)
{
    uint16_t current_offset = OFFSET_SIZE * 2 + get_padding_size(OFFSET_SIZE * 2, PACKET_ALIGNMENT);

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[current_offset + PACKET_ID_OFFSET])) = id;
    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[current_offset + PACKET_LENGTH_OFFSET])) = length;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[0])) = serializer->_tail_offset;

    return serializer->_buffer;
}