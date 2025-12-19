
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



namespace MyGame {
struct PZEM004Tv30Data; 



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





struct PZEM004Tv30Data  {

#define PZEM004TV30DATA_VOLTAGE_OFFSET 0
#define PZEM004TV30DATA_CURRENT_OFFSET 4
#define PZEM004TV30DATA_POWER_OFFSET 8
#define PZEM004TV30DATA_ENERGY_OFFSET 12
#define PZEM004TV30DATA_FREQ_OFFSET 16
#define PZEM004TV30DATA_PF_OFFSET 20
#define PZEM004TV30DATA_ALARMS_OFFSET 24
#define PZEM004TV30DATA_PAD26_OFFSET 26
#define PZEM004TV30DATA_ALIGNMENT 4
#define PZEM004TV30DATA_SIZE 28


NAKEDBYTES_FORCE_INLINE const float voltage() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_VOLTAGE_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const float current() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_CURRENT_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const float power() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_POWER_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const float energy() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_ENERGY_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const float freq() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_FREQ_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const float pf() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_PF_OFFSET ]);
}

NAKEDBYTES_FORCE_INLINE const uint16_t alarms() const {
return *reinterpret_cast<const uint16_t*>(&data_[PZEM004TV30DATA_ALARMS_OFFSET ]);
}

static constexpr size_t nakedbytes_sizeof = 28;

private:
PZEM004Tv30Data() =delete;
PZEM004Tv30Data(const PZEM004Tv30Data &) =delete;
PZEM004Tv30Data& operator=(const PZEM004Tv30Data &) =delete;
unsigned char data_[1];

};







struct PZEM004Tv30DataRoot  {

#define PZEM004TV30DATA_VOLTAGE_OFFSET 0
#define PZEM004TV30DATA_CURRENT_OFFSET 4
#define PZEM004TV30DATA_POWER_OFFSET 8
#define PZEM004TV30DATA_ENERGY_OFFSET 12
#define PZEM004TV30DATA_FREQ_OFFSET 16
#define PZEM004TV30DATA_PF_OFFSET 20
#define PZEM004TV30DATA_ALARMS_OFFSET 24
#define PZEM004TV30DATA_PAD26_OFFSET 26
#define PZEM004TV30DATA_ALIGNMENT 4
#define PZEM004TV30DATA_SIZE 28


NAKEDBYTES_FORCE_INLINE const float voltage() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_VOLTAGE_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const float current() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_CURRENT_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const float power() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_POWER_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const float energy() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_ENERGY_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const float freq() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_FREQ_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const float pf() const {
return *reinterpret_cast<const float*>(&data_[PZEM004TV30DATA_PF_OFFSET + 2* OFFSET_SIZE]);
}

NAKEDBYTES_FORCE_INLINE const uint16_t alarms() const {
return *reinterpret_cast<const uint16_t*>(&data_[PZEM004TV30DATA_ALARMS_OFFSET + 2* OFFSET_SIZE]);
}

static constexpr size_t nakedbytes_sizeof = 28;

private:
PZEM004Tv30DataRoot() =delete;
PZEM004Tv30DataRoot(const PZEM004Tv30DataRoot &) =delete;
PZEM004Tv30DataRoot& operator=(const PZEM004Tv30DataRoot &) =delete;
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




struct PZEM004Tv30DataStruct {
float voltage;
float current;
float power;
float energy;
float freq;
float pf;
uint16_t alarms;
};




inline SerializeOffset<PZEM004Tv30Data> serialize_pzem004tv30data(Serializer *const serializer,
 const float voltage,
 const float current,
 const float power,
 const float energy,
 const float freq,
 const float pf,
 const uint16_t alarms){
SerializeOffset<PZEM004Tv30Data> pzem004tv30data_offset;
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PZEM004TV30DATA_ALIGNMENT);
serializer->make_buffer_adequate();
pzem004tv30data_offset.offset = serializer->_tail_offset;

*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + PZEM004TV30DATA_VOLTAGE_OFFSET])) = voltage;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + PZEM004TV30DATA_CURRENT_OFFSET])) = current;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + PZEM004TV30DATA_POWER_OFFSET])) = power;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + PZEM004TV30DATA_ENERGY_OFFSET])) = energy;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + PZEM004TV30DATA_FREQ_OFFSET])) = freq;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + PZEM004TV30DATA_PF_OFFSET])) = pf;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + PZEM004TV30DATA_ALARMS_OFFSET])) = alarms;
serializer->_tail_offset += PZEM004TV30DATA_SIZE;
return pzem004tv30data_offset;
}



inline SerializeOffset<Vector<PZEM004Tv30DataStruct>> serialize_vector_pzem004tv30data_struct(Serializer *const serializer, std::vector<PZEM004Tv30DataStruct> data_array){
SerializeOffset<Vector<PZEM004Tv30DataStruct>> data_array_offset;
uint16_t len = data_array.size();
serializer->_tail_offset += get_padding_size(serializer->_tail_offset, OFFSET_SIZE);
serializer->make_buffer_adequate();
data_array_offset.offset = serializer->_tail_offset;
*reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
serializer->_tail_offset += OFFSET_SIZE;serializer->_tail_offset += get_padding_size(serializer->_tail_offset, PZEM004TV30DATA_ALIGNMENT);for (uint16_t i = 0; i < len; i++){*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + (PZEM004TV30DATA_SIZE * i) + PZEM004TV30DATA_VOLTAGE_OFFSET])) = data_array[i].voltage;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + (PZEM004TV30DATA_SIZE * i) + PZEM004TV30DATA_CURRENT_OFFSET])) = data_array[i].current;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + (PZEM004TV30DATA_SIZE * i) + PZEM004TV30DATA_POWER_OFFSET])) = data_array[i].power;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + (PZEM004TV30DATA_SIZE * i) + PZEM004TV30DATA_ENERGY_OFFSET])) = data_array[i].energy;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + (PZEM004TV30DATA_SIZE * i) + PZEM004TV30DATA_FREQ_OFFSET])) = data_array[i].freq;
*reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset  + (PZEM004TV30DATA_SIZE * i) + PZEM004TV30DATA_PF_OFFSET])) = data_array[i].pf;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset  + (PZEM004TV30DATA_SIZE * i) + PZEM004TV30DATA_ALARMS_OFFSET])) = data_array[i].alarms;
serializer->_tail_offset += (PZEM004TV30DATA_SIZE * len);
}return data_array_offset;}



inline unsigned char *serialize_pzem004tv30data_root(Serializer *const serializer,
 const float voltage,
 const float current,
 const float power,
 const float energy,
 const float freq,
 const float pf,
 const uint16_t alarms){
uint16_t current_offset = OFFSET_SIZE * 2 + get_padding_size(OFFSET_SIZE * 2, PZEM004TV30DATA_ALIGNMENT);


*reinterpret_cast<float *>(&(serializer->_buffer[current_offset  + PZEM004TV30DATA_VOLTAGE_OFFSET])) = voltage;
*reinterpret_cast<float *>(&(serializer->_buffer[current_offset  + PZEM004TV30DATA_CURRENT_OFFSET])) = current;
*reinterpret_cast<float *>(&(serializer->_buffer[current_offset  + PZEM004TV30DATA_POWER_OFFSET])) = power;
*reinterpret_cast<float *>(&(serializer->_buffer[current_offset  + PZEM004TV30DATA_ENERGY_OFFSET])) = energy;
*reinterpret_cast<float *>(&(serializer->_buffer[current_offset  + PZEM004TV30DATA_FREQ_OFFSET])) = freq;
*reinterpret_cast<float *>(&(serializer->_buffer[current_offset  + PZEM004TV30DATA_PF_OFFSET])) = pf;
*reinterpret_cast<uint16_t *>(&(serializer->_buffer[current_offset  + PZEM004TV30DATA_ALARMS_OFFSET])) = alarms;

*reinterpret_cast<uint16_t*>(&(serializer->_buffer[0])) = serializer->_tail_offset;

return serializer->_buffer;
}
} // namespace MyGame
