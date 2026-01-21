#ifndef __SUNSPEC_MODEL_STRUCT_OFFSET_NAKEDBYTES_GENERATED_H
#define __SUNSPEC_MODEL_STRUCT_OFFSET_NAKEDBYTES_GENERATED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <type_traits>
#include <vector>

#define OFFSET_SIZE (2)
#define VERSION (10)

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
    NAKEDBYTES_FORCE_INLINE uint16_t get_padding_size(uint16_t offset, uint16_t alignment)
    {
        return static_cast<uint16_t>((alignment - (offset % alignment)) % alignment);
    }

    struct String
    {
        static constexpr uint16_t nakedbytes_sizeof = 2;

#define STRING_LENGTH_OFFSET 0
        NAKEDBYTES_FORCE_INLINE uint16_t length() const
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
        String(const String &other) = delete;
        String &operator=(const String &other) = delete;
    };

    template <typename T, typename Enable = void>
    struct Offset
    {
        static constexpr uint16_t nakedbytes_sizeof = 2;

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int16_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE const T *value_ptr() const
        {
            const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
            return reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &value() const
        {
            const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
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
        static constexpr uint16_t nakedbytes_sizeof = sizeof(T);

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int16_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE const T *value_ptr() const
        {
            const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
            return reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &value() const
        {
            const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
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

        static constexpr uint16_t nakedbytes_sizeof = 2;

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int16_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE uint16_t size() const
        {
            const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
            return *reinterpret_cast<const uint16_t *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T *get(uint16_t index) const
        {
            const int16_t offset = static_cast<int16_t>(*reinterpret_cast<const int16_t *>(&data_[0])) + static_cast<int16_t>(OFFSET_SIZE) + static_cast<int16_t>(T::nakedbytes_sizeof) * static_cast<int16_t>(index);
            return reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &operator[](uint16_t index) const
        {
            const int16_t offset = static_cast<int16_t>(*reinterpret_cast<const int16_t *>(&data_[0]) + OFFSET_SIZE + T::nakedbytes_sizeof * index);
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

            Iterator(uint16_t index, const Vector<T> &vec) : index_(index), vec_{vec} {}

            reference operator*() const { return vec_[index_]; }
            pointer operator->() { return vec_.get(index); }
            Iterator &operator++()
            {
                index_++;
                return vec_[index_];
            }
           
            friend bool operator==(const Iterator &a, const Iterator &b) { return a.index_ == b.index_; };
            friend bool operator!=(const Iterator &a, const Iterator &b) { return a.index_ != b.index_; };

        private:
            uint16_t index_;
            const Vector<T> &vec_;
        };

    private:
        unsigned char data_[1];

        Vector() = delete;
        Vector(const Vector &other) = delete;
        Vector &operator=(const Vector &other) = delete;
    };

    template <typename T>
    struct Vector<T, typename std::enable_if<(std::is_floating_point<T>::value || std::is_integral<T>::value)>::type>
    {

        static constexpr uint16_t nakedbytes_sizeof = 2;

        NAKEDBYTES_FORCE_INLINE bool is_null() const
        {
            return *reinterpret_cast<const int16_t *>(&data_[0]) == 0;
        }

        NAKEDBYTES_FORCE_INLINE uint16_t size() const
        {
            const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[0]);
            return *reinterpret_cast<const uint16_t *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &get(uint16_t index) const
        {
            const int16_t offset = static_cast<int16_t>(*reinterpret_cast<const int16_t *>(&data_[0])) + static_cast<int16_t>(OFFSET_SIZE) + static_cast<int16_t>(OFFSET_SIZE) * static_cast<int16_t>(index);
            return *reinterpret_cast<const T *>(&data_[offset]);
        }

        NAKEDBYTES_FORCE_INLINE const T &operator[](uint16_t index) const
        {
            const int16_t offset = static_cast<int16_t>(*reinterpret_cast<const int16_t *>(&data_[0])) + static_cast<int16_t>(OFFSET_SIZE) + static_cast<int16_t>(OFFSET_SIZE) * static_cast<int16_t>(index);
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

            Iterator(uint16_t index, const Vector<T> &vec) : index_(index), vec_{vec} {}

            reference operator*() const { return vec_[index_]; }
            pointer operator->() { return vec_.get(index); }
            Iterator &operator++()
            {
                index_++;
                return vec_[index_];
            }
           
            friend bool operator==(const Iterator &a, const Iterator &b) { return a.index_ == b.index_; };
            friend bool operator!=(const Iterator &a, const Iterator &b) { return a.index_ != b.index_; };

        private:
            uint16_t index_;
            const Vector<T> &vec_;
        };
        
    private:
        unsigned char data_[1];

        Vector() = delete;
        Vector(const Vector &other) = delete;
        Vector &operator=(const Vector &other) = delete;
    };
}; // namespace nakedbytes

struct Enum64;
struct Acc16;
struct Float32;
struct Uint64;
struct Sint64;
struct Eui48;
struct Float64;
struct SunspecGroupDef;
struct Pad16;
struct Enum16;
struct SunspecModelDef;
struct Enum32;
struct Stringx;
struct Bitfield16;
struct SunspecPointDef;
struct Bitfield32;
struct Bitfield64;
struct SunsSf;
struct Uint16;
struct Acc32;
struct SunspecPointData;
struct Sint32;
struct Ipv6Addr;
struct Acc64;
struct IpAddr;
struct Uint32;
struct Sint16;
struct Raw16;

enum SunspecPointAccess : uint8_t
{

    SunspecPointAccess_kR,
    SunspecPointAccess_kRW,
};

inline const char *SunspecPointAccess_to_string(SunspecPointAccess value)
{
    switch (value)
    {
    case SunspecPointAccess_kR:
        return "SunspecPointAccess_kR";
    case SunspecPointAccess_kRW:
        return "SunspecPointAccess_kRW";
    default:
        return NULL;
    }
}

struct Enum64
{

#define ENUM64_VALUE_OFFSET 0
#define ENUM64_ALIGNMENT 8
#define ENUM64_SIZE 8
#define ENUM64_UNPADDED_SIZE 8

    NAKEDBYTES_FORCE_INLINE uint64_t value() const
    {
        return *reinterpret_cast<const uint64_t *>(&data_[ENUM64_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 8;

private:
    Enum64() = delete;
    Enum64(const Enum64 &) = delete;
    Enum64 &operator=(const Enum64 &) = delete;
    unsigned char data_[1];
};

struct Acc16
{

#define ACC16_VALUE_OFFSET 0
#define ACC16_ALIGNMENT 2
#define ACC16_SIZE 2
#define ACC16_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE uint16_t value() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[ACC16_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Acc16() = delete;
    Acc16(const Acc16 &) = delete;
    Acc16 &operator=(const Acc16 &) = delete;
    unsigned char data_[1];
};

struct Float32
{

#define FLOAT32_VALUE_OFFSET 0
#define FLOAT32_ALIGNMENT 4
#define FLOAT32_SIZE 4
#define FLOAT32_UNPADDED_SIZE 4

    NAKEDBYTES_FORCE_INLINE float value() const
    {
        return *reinterpret_cast<const float *>(&data_[FLOAT32_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 4;

private:
    Float32() = delete;
    Float32(const Float32 &) = delete;
    Float32 &operator=(const Float32 &) = delete;
    unsigned char data_[1];
};

enum SunspecPointMandatory : uint8_t
{

    SunspecPointMandatory_kM,
    SunspecPointMandatory_kO,
};

inline const char *SunspecPointMandatory_to_string(SunspecPointMandatory value)
{
    switch (value)
    {
    case SunspecPointMandatory_kM:
        return "SunspecPointMandatory_kM";
    case SunspecPointMandatory_kO:
        return "SunspecPointMandatory_kO";
    default:
        return NULL;
    }
}

struct Uint64
{

#define UINT64_VALUE_OFFSET 0
#define UINT64_ALIGNMENT 8
#define UINT64_SIZE 8
#define UINT64_UNPADDED_SIZE 8

    NAKEDBYTES_FORCE_INLINE uint64_t value() const
    {
        return *reinterpret_cast<const uint64_t *>(&data_[UINT64_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 8;

private:
    Uint64() = delete;
    Uint64(const Uint64 &) = delete;
    Uint64 &operator=(const Uint64 &) = delete;
    unsigned char data_[1];
};

struct Sint64
{

#define SINT64_VALUE_OFFSET 0
#define SINT64_ALIGNMENT 8
#define SINT64_SIZE 8
#define SINT64_UNPADDED_SIZE 8

    NAKEDBYTES_FORCE_INLINE int64_t value() const
    {
        return *reinterpret_cast<const int64_t *>(&data_[SINT64_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 8;

private:
    Sint64() = delete;
    Sint64(const Sint64 &) = delete;
    Sint64 &operator=(const Sint64 &) = delete;
    unsigned char data_[1];
};

struct Eui48
{

#define EUI48_VALUE0_OFFSET 0
#define EUI48_VALUE1_OFFSET 2
#define EUI48_VALUE2_OFFSET 4
#define EUI48_ALIGNMENT 2
#define EUI48_SIZE 6
#define EUI48_UNPADDED_SIZE 6

    NAKEDBYTES_FORCE_INLINE uint16_t value0() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[EUI48_VALUE0_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint16_t value1() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[EUI48_VALUE1_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint16_t value2() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[EUI48_VALUE2_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 6;

private:
    Eui48() = delete;
    Eui48(const Eui48 &) = delete;
    Eui48 &operator=(const Eui48 &) = delete;
    unsigned char data_[1];
};

struct Float64
{

#define FLOAT64_VALUE_OFFSET 0
#define FLOAT64_ALIGNMENT 8
#define FLOAT64_SIZE 8
#define FLOAT64_UNPADDED_SIZE 8

    NAKEDBYTES_FORCE_INLINE double value() const
    {
        return *reinterpret_cast<const double *>(&data_[FLOAT64_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 8;

private:
    Float64() = delete;
    Float64(const Float64 &) = delete;
    Float64 &operator=(const Float64 &) = delete;
    unsigned char data_[1];
};

enum SunspecPointData_enum : uint16_t
{

    SunspecPointData_enum_Uint16,
    SunspecPointData_enum_Sint16,
    SunspecPointData_enum_Uint32,
    SunspecPointData_enum_Sint32,
    SunspecPointData_enum_Uint64,
    SunspecPointData_enum_Sint64,
    SunspecPointData_enum_Float32,
    SunspecPointData_enum_Float64,
    SunspecPointData_enum_Stringx,
    SunspecPointData_enum_Pad16,
    SunspecPointData_enum_Raw16,
    SunspecPointData_enum_Enum16,
    SunspecPointData_enum_Enum32,
    SunspecPointData_enum_Enum64,
    SunspecPointData_enum_Bitfield16,
    SunspecPointData_enum_Bitfield32,
    SunspecPointData_enum_Bitfield64,
    SunspecPointData_enum_SunsSf,
    SunspecPointData_enum_Acc16,
    SunspecPointData_enum_Acc32,
    SunspecPointData_enum_Acc64,
    SunspecPointData_enum_Eui48,
    SunspecPointData_enum_IpAddr,
    SunspecPointData_enum_Ipv6Addr,
};

inline const char *SunspecPointData_enum_to_string(SunspecPointData_enum value)
{
    switch (value)
    {
    case SunspecPointData_enum_Uint16:
        return "SunspecPointData_enum_Uint16";
    case SunspecPointData_enum_Sint16:
        return "SunspecPointData_enum_Sint16";
    case SunspecPointData_enum_Uint32:
        return "SunspecPointData_enum_Uint32";
    case SunspecPointData_enum_Sint32:
        return "SunspecPointData_enum_Sint32";
    case SunspecPointData_enum_Uint64:
        return "SunspecPointData_enum_Uint64";
    case SunspecPointData_enum_Sint64:
        return "SunspecPointData_enum_Sint64";
    case SunspecPointData_enum_Float32:
        return "SunspecPointData_enum_Float32";
    case SunspecPointData_enum_Float64:
        return "SunspecPointData_enum_Float64";
    case SunspecPointData_enum_Stringx:
        return "SunspecPointData_enum_Stringx";
    case SunspecPointData_enum_Pad16:
        return "SunspecPointData_enum_Pad16";
    case SunspecPointData_enum_Raw16:
        return "SunspecPointData_enum_Raw16";
    case SunspecPointData_enum_Enum16:
        return "SunspecPointData_enum_Enum16";
    case SunspecPointData_enum_Enum32:
        return "SunspecPointData_enum_Enum32";
    case SunspecPointData_enum_Enum64:
        return "SunspecPointData_enum_Enum64";
    case SunspecPointData_enum_Bitfield16:
        return "SunspecPointData_enum_Bitfield16";
    case SunspecPointData_enum_Bitfield32:
        return "SunspecPointData_enum_Bitfield32";
    case SunspecPointData_enum_Bitfield64:
        return "SunspecPointData_enum_Bitfield64";
    case SunspecPointData_enum_SunsSf:
        return "SunspecPointData_enum_SunsSf";
    case SunspecPointData_enum_Acc16:
        return "SunspecPointData_enum_Acc16";
    case SunspecPointData_enum_Acc32:
        return "SunspecPointData_enum_Acc32";
    case SunspecPointData_enum_Acc64:
        return "SunspecPointData_enum_Acc64";
    case SunspecPointData_enum_Eui48:
        return "SunspecPointData_enum_Eui48";
    case SunspecPointData_enum_IpAddr:
        return "SunspecPointData_enum_IpAddr";
    case SunspecPointData_enum_Ipv6Addr:
        return "SunspecPointData_enum_Ipv6Addr";
    default:
        return NULL;
    }
}

struct Uint16
{

#define UINT16_VALUE_OFFSET 0
#define UINT16_ALIGNMENT 2
#define UINT16_SIZE 2
#define UINT16_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE uint16_t value() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[UINT16_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Uint16() = delete;
    Uint16(const Uint16 &) = delete;
    Uint16 &operator=(const Uint16 &) = delete;
    unsigned char data_[1];
};

struct Sint16
{

#define SINT16_VALUE_OFFSET 0
#define SINT16_ALIGNMENT 2
#define SINT16_SIZE 2
#define SINT16_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE int16_t value() const
    {
        return *reinterpret_cast<const int16_t *>(&data_[SINT16_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Sint16() = delete;
    Sint16(const Sint16 &) = delete;
    Sint16 &operator=(const Sint16 &) = delete;
    unsigned char data_[1];
};

struct Uint32
{

#define UINT32_VALUE_OFFSET 0
#define UINT32_ALIGNMENT 4
#define UINT32_SIZE 4
#define UINT32_UNPADDED_SIZE 4

    NAKEDBYTES_FORCE_INLINE uint32_t value() const
    {
        return *reinterpret_cast<const uint32_t *>(&data_[UINT32_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 4;

private:
    Uint32() = delete;
    Uint32(const Uint32 &) = delete;
    Uint32 &operator=(const Uint32 &) = delete;
    unsigned char data_[1];
};

struct Sint32
{

#define SINT32_VALUE_OFFSET 0
#define SINT32_ALIGNMENT 4
#define SINT32_SIZE 4
#define SINT32_UNPADDED_SIZE 4

    NAKEDBYTES_FORCE_INLINE int32_t value() const
    {
        return *reinterpret_cast<const int32_t *>(&data_[SINT32_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 4;

private:
    Sint32() = delete;
    Sint32(const Sint32 &) = delete;
    Sint32 &operator=(const Sint32 &) = delete;
    unsigned char data_[1];
};

struct Stringx
{

#define STRINGX_VALUE_OFFSET 0
#define STRINGX_ALIGNMENT 2
#define STRINGX_SIZE 2
#define STRINGX_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *value() const
    {
        const int16_t offset = STRINGX_VALUE_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Stringx() = delete;
    Stringx(const Stringx &) = delete;
    Stringx &operator=(const Stringx &) = delete;
    unsigned char data_[1];
};

struct Pad16
{

#define PAD16_VALUE_OFFSET 0
#define PAD16_ALIGNMENT 2
#define PAD16_SIZE 2
#define PAD16_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE uint16_t value() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[PAD16_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Pad16() = delete;
    Pad16(const Pad16 &) = delete;
    Pad16 &operator=(const Pad16 &) = delete;
    unsigned char data_[1];
};

struct Raw16
{

#define RAW16_VALUE_OFFSET 0
#define RAW16_ALIGNMENT 2
#define RAW16_SIZE 2
#define RAW16_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE uint16_t value() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[RAW16_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Raw16() = delete;
    Raw16(const Raw16 &) = delete;
    Raw16 &operator=(const Raw16 &) = delete;
    unsigned char data_[1];
};

struct Enum16
{

#define ENUM16_VALUE_OFFSET 0
#define ENUM16_ALIGNMENT 2
#define ENUM16_SIZE 2
#define ENUM16_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE uint16_t value() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[ENUM16_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Enum16() = delete;
    Enum16(const Enum16 &) = delete;
    Enum16 &operator=(const Enum16 &) = delete;
    unsigned char data_[1];
};

struct Enum32
{

#define ENUM32_VALUE_OFFSET 0
#define ENUM32_ALIGNMENT 4
#define ENUM32_SIZE 4
#define ENUM32_UNPADDED_SIZE 4

    NAKEDBYTES_FORCE_INLINE uint32_t value() const
    {
        return *reinterpret_cast<const uint32_t *>(&data_[ENUM32_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 4;

private:
    Enum32() = delete;
    Enum32(const Enum32 &) = delete;
    Enum32 &operator=(const Enum32 &) = delete;
    unsigned char data_[1];
};

struct Bitfield16
{

#define BITFIELD16_VALUE_OFFSET 0
#define BITFIELD16_ALIGNMENT 2
#define BITFIELD16_SIZE 2
#define BITFIELD16_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE uint16_t value() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[BITFIELD16_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    Bitfield16() = delete;
    Bitfield16(const Bitfield16 &) = delete;
    Bitfield16 &operator=(const Bitfield16 &) = delete;
    unsigned char data_[1];
};

struct Bitfield32
{

#define BITFIELD32_VALUE_OFFSET 0
#define BITFIELD32_ALIGNMENT 4
#define BITFIELD32_SIZE 4
#define BITFIELD32_UNPADDED_SIZE 4

    NAKEDBYTES_FORCE_INLINE uint32_t value() const
    {
        return *reinterpret_cast<const uint32_t *>(&data_[BITFIELD32_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 4;

private:
    Bitfield32() = delete;
    Bitfield32(const Bitfield32 &) = delete;
    Bitfield32 &operator=(const Bitfield32 &) = delete;
    unsigned char data_[1];
};

struct Bitfield64
{

#define BITFIELD64_VALUE_OFFSET 0
#define BITFIELD64_ALIGNMENT 8
#define BITFIELD64_SIZE 8
#define BITFIELD64_UNPADDED_SIZE 8

    NAKEDBYTES_FORCE_INLINE uint64_t value() const
    {
        return *reinterpret_cast<const uint64_t *>(&data_[BITFIELD64_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 8;

private:
    Bitfield64() = delete;
    Bitfield64(const Bitfield64 &) = delete;
    Bitfield64 &operator=(const Bitfield64 &) = delete;
    unsigned char data_[1];
};

struct SunsSf
{

#define SUNSSF_VALUE_OFFSET 0
#define SUNSSF_ALIGNMENT 2
#define SUNSSF_SIZE 2
#define SUNSSF_UNPADDED_SIZE 2

    NAKEDBYTES_FORCE_INLINE uint16_t value() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[SUNSSF_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 2;

private:
    SunsSf() = delete;
    SunsSf(const SunsSf &) = delete;
    SunsSf &operator=(const SunsSf &) = delete;
    unsigned char data_[1];
};

struct Acc32
{

#define ACC32_VALUE_OFFSET 0
#define ACC32_ALIGNMENT 4
#define ACC32_SIZE 4
#define ACC32_UNPADDED_SIZE 4

    NAKEDBYTES_FORCE_INLINE uint32_t value() const
    {
        return *reinterpret_cast<const uint32_t *>(&data_[ACC32_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 4;

private:
    Acc32() = delete;
    Acc32(const Acc32 &) = delete;
    Acc32 &operator=(const Acc32 &) = delete;
    unsigned char data_[1];
};

struct Acc64
{

#define ACC64_VALUE_OFFSET 0
#define ACC64_ALIGNMENT 8
#define ACC64_SIZE 8
#define ACC64_UNPADDED_SIZE 8

    NAKEDBYTES_FORCE_INLINE uint64_t value() const
    {
        return *reinterpret_cast<const uint64_t *>(&data_[ACC64_VALUE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 8;

private:
    Acc64() = delete;
    Acc64(const Acc64 &) = delete;
    Acc64 &operator=(const Acc64 &) = delete;
    unsigned char data_[1];
};

struct IpAddr
{

#define IPADDR_OCTET1_OFFSET 0
#define IPADDR_OCTET2_OFFSET 1
#define IPADDR_OCTET3_OFFSET 2
#define IPADDR_OCTET4_OFFSET 3
#define IPADDR_ALIGNMENT 1
#define IPADDR_SIZE 4
#define IPADDR_UNPADDED_SIZE 4

    NAKEDBYTES_FORCE_INLINE uint8_t octet1() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPADDR_OCTET1_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet2() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPADDR_OCTET2_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet3() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPADDR_OCTET3_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet4() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPADDR_OCTET4_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 4;

private:
    IpAddr() = delete;
    IpAddr(const IpAddr &) = delete;
    IpAddr &operator=(const IpAddr &) = delete;
    unsigned char data_[1];
};

struct Ipv6Addr
{

#define IPV6ADDR_OCTET0_OFFSET 0
#define IPV6ADDR_OCTET1_OFFSET 1
#define IPV6ADDR_OCTET2_OFFSET 2
#define IPV6ADDR_OCTET3_OFFSET 3
#define IPV6ADDR_OCTET4_OFFSET 4
#define IPV6ADDR_OCTET5_OFFSET 5
#define IPV6ADDR_ALIGNMENT 1
#define IPV6ADDR_SIZE 6
#define IPV6ADDR_UNPADDED_SIZE 6

    NAKEDBYTES_FORCE_INLINE uint8_t octet0() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPV6ADDR_OCTET0_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet1() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPV6ADDR_OCTET1_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet2() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPV6ADDR_OCTET2_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet3() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPV6ADDR_OCTET3_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet4() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPV6ADDR_OCTET4_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t octet5() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[IPV6ADDR_OCTET5_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 6;

private:
    Ipv6Addr() = delete;
    Ipv6Addr(const Ipv6Addr &) = delete;
    Ipv6Addr &operator=(const Ipv6Addr &) = delete;
    unsigned char data_[1];
};

struct SunspecPointData
{

#define SUNSPECPOINTDATA_TYPE_OFFSET 0
#define SUNSPECPOINTDATA_DATA_OFFSET 2
#define SUNSPECPOINTDATA_ALIGNMENT 2
#define SUNSPECPOINTDATA_SIZE 2

    bool is_null() const
    {
        return (type() == 0) or (*reinterpret_cast<const int16_t *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) == 0);
    }

    const unsigned char *raw_data() const
    {
        const int16_t offset = *reinterpret_cast<const int16_t *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) + SUNSPECPOINTDATA_DATA_OFFSET;
        return reinterpret_cast<const unsigned char *>(&data_[offset]);
    }
    SunspecPointData_enum type() const
    {
        return *reinterpret_cast<const SunspecPointData_enum *>(&data_[SUNSPECPOINTDATA_TYPE_OFFSET]);
    }

    const ::nakedbytes::Offset<Uint16> *data_as_Uint16() const
    {
        return type() == SunspecPointData_enum_Uint16 ? reinterpret_cast<const ::nakedbytes::Offset<Uint16> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Sint16> *data_as_Sint16() const
    {
        return type() == SunspecPointData_enum_Sint16 ? reinterpret_cast<const ::nakedbytes::Offset<Sint16> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Uint32> *data_as_Uint32() const
    {
        return type() == SunspecPointData_enum_Uint32 ? reinterpret_cast<const ::nakedbytes::Offset<Uint32> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Sint32> *data_as_Sint32() const
    {
        return type() == SunspecPointData_enum_Sint32 ? reinterpret_cast<const ::nakedbytes::Offset<Sint32> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Uint64> *data_as_Uint64() const
    {
        return type() == SunspecPointData_enum_Uint64 ? reinterpret_cast<const ::nakedbytes::Offset<Uint64> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Sint64> *data_as_Sint64() const
    {
        return type() == SunspecPointData_enum_Sint64 ? reinterpret_cast<const ::nakedbytes::Offset<Sint64> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Float32> *data_as_Float32() const
    {
        return type() == SunspecPointData_enum_Float32 ? reinterpret_cast<const ::nakedbytes::Offset<Float32> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Float64> *data_as_Float64() const
    {
        return type() == SunspecPointData_enum_Float64 ? reinterpret_cast<const ::nakedbytes::Offset<Float64> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Stringx> *data_as_Stringx() const
    {
        return type() == SunspecPointData_enum_Stringx ? reinterpret_cast<const ::nakedbytes::Offset<Stringx> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Pad16> *data_as_Pad16() const
    {
        return type() == SunspecPointData_enum_Pad16 ? reinterpret_cast<const ::nakedbytes::Offset<Pad16> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Raw16> *data_as_Raw16() const
    {
        return type() == SunspecPointData_enum_Raw16 ? reinterpret_cast<const ::nakedbytes::Offset<Raw16> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Enum16> *data_as_Enum16() const
    {
        return type() == SunspecPointData_enum_Enum16 ? reinterpret_cast<const ::nakedbytes::Offset<Enum16> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Enum32> *data_as_Enum32() const
    {
        return type() == SunspecPointData_enum_Enum32 ? reinterpret_cast<const ::nakedbytes::Offset<Enum32> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Enum64> *data_as_Enum64() const
    {
        return type() == SunspecPointData_enum_Enum64 ? reinterpret_cast<const ::nakedbytes::Offset<Enum64> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Bitfield16> *data_as_Bitfield16() const
    {
        return type() == SunspecPointData_enum_Bitfield16 ? reinterpret_cast<const ::nakedbytes::Offset<Bitfield16> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Bitfield32> *data_as_Bitfield32() const
    {
        return type() == SunspecPointData_enum_Bitfield32 ? reinterpret_cast<const ::nakedbytes::Offset<Bitfield32> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Bitfield64> *data_as_Bitfield64() const
    {
        return type() == SunspecPointData_enum_Bitfield64 ? reinterpret_cast<const ::nakedbytes::Offset<Bitfield64> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<SunsSf> *data_as_SunsSf() const
    {
        return type() == SunspecPointData_enum_SunsSf ? reinterpret_cast<const ::nakedbytes::Offset<SunsSf> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Acc16> *data_as_Acc16() const
    {
        return type() == SunspecPointData_enum_Acc16 ? reinterpret_cast<const ::nakedbytes::Offset<Acc16> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Acc32> *data_as_Acc32() const
    {
        return type() == SunspecPointData_enum_Acc32 ? reinterpret_cast<const ::nakedbytes::Offset<Acc32> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Acc64> *data_as_Acc64() const
    {
        return type() == SunspecPointData_enum_Acc64 ? reinterpret_cast<const ::nakedbytes::Offset<Acc64> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Eui48> *data_as_Eui48() const
    {
        return type() == SunspecPointData_enum_Eui48 ? reinterpret_cast<const ::nakedbytes::Offset<Eui48> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<IpAddr> *data_as_IpAddr() const
    {
        return type() == SunspecPointData_enum_IpAddr ? reinterpret_cast<const ::nakedbytes::Offset<IpAddr> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

    const ::nakedbytes::Offset<Ipv6Addr> *data_as_Ipv6Addr() const
    {
        return type() == SunspecPointData_enum_Ipv6Addr ? reinterpret_cast<const ::nakedbytes::Offset<Ipv6Addr> *>(&data_[SUNSPECPOINTDATA_DATA_OFFSET]) : nullptr;
    }

private:
    SunspecPointData() = delete;
    SunspecPointData(const SunspecPointData &) = delete;
    SunspecPointData &operator=(const SunspecPointData &) = delete;
    unsigned char data_[1];
};

struct SunspecPointDef
{

#define SUNSPECPOINTDEF_ID_OFFSET 0
#define SUNSPECPOINTDEF_SF_ID_OFFSET 2
#define SUNSPECPOINTDEF_UNITS_OFFSET 4
#define SUNSPECPOINTDEF_LABEL_OFFSET 6
#define SUNSPECPOINTDEF_DATA_TYPE_OFFSET 8
#define SUNSPECPOINTDEF_DATA_OFFSET 10
#define SUNSPECPOINTDEF_COUNT_OFFSET 12
#define SUNSPECPOINTDEF_PAD13_OFFSET 13
#define SUNSPECPOINTDEF_COUNT_POINT_ID_OFFSET 14
#define SUNSPECPOINTDEF_SIZE_OFFSET 16
#define SUNSPECPOINTDEF_SF_OFFSET 17
#define SUNSPECPOINTDEF_ACCESS_OFFSET 18
#define SUNSPECPOINTDEF_MANDATORY_OFFSET 19
#define SUNSPECPOINTDEF_ALIGNMENT 2
#define SUNSPECPOINTDEF_SIZE 20
#define SUNSPECPOINTDEF_UNPADDED_SIZE 20

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *id() const
    {
        const int16_t offset = SUNSPECPOINTDEF_ID_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *sf_id() const
    {
        const int16_t offset = SUNSPECPOINTDEF_SF_ID_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *units() const
    {
        const int16_t offset = SUNSPECPOINTDEF_UNITS_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *label() const
    {
        const int16_t offset = SUNSPECPOINTDEF_LABEL_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE SunspecPointData_enum data_type() const
    {
        return *reinterpret_cast<const SunspecPointData_enum *>(&data_[SUNSPECPOINTDEF_DATA_TYPE_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE const SunspecPointData *data() const
    {
        const int16_t offset = SUNSPECPOINTDEF_DATA_TYPE_OFFSET;
        return reinterpret_cast<const SunspecPointData *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t count() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[SUNSPECPOINTDEF_COUNT_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *count_point_id() const
    {
        const int16_t offset = SUNSPECPOINTDEF_COUNT_POINT_ID_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t size() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[SUNSPECPOINTDEF_SIZE_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE int8_t sf() const
    {
        return *reinterpret_cast<const int8_t *>(&data_[SUNSPECPOINTDEF_SF_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE SunspecPointAccess access() const
    {
        return *reinterpret_cast<const SunspecPointAccess *>(&data_[SUNSPECPOINTDEF_ACCESS_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE SunspecPointMandatory mandatory() const
    {
        return *reinterpret_cast<const SunspecPointMandatory *>(&data_[SUNSPECPOINTDEF_MANDATORY_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 20;

private:
    SunspecPointDef() = delete;
    SunspecPointDef(const SunspecPointDef &) = delete;
    SunspecPointDef &operator=(const SunspecPointDef &) = delete;
    unsigned char data_[1];
};

enum SunspecGroupType : uint8_t
{

    SunspecGroupType_kGroup,
    SunspecGroupType_kSync,
};

inline const char *SunspecGroupType_to_string(SunspecGroupType value)
{
    switch (value)
    {
    case SunspecGroupType_kGroup:
        return "SunspecGroupType_kGroup";
    case SunspecGroupType_kSync:
        return "SunspecGroupType_kSync";
    default:
        return NULL;
    }
}

struct SunspecGroupDef
{

#define SUNSPECGROUPDEF_ID_OFFSET 0
#define SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET 2
#define SUNSPECGROUPDEF_POINTS_OFFSET 4
#define SUNSPECGROUPDEF_GROUPS_OFFSET 6
#define SUNSPECGROUPDEF_LABEL_OFFSET 8
#define SUNSPECGROUPDEF_COUNT_OFFSET 10
#define SUNSPECGROUPDEF_TYPE_OFFSET 11
#define SUNSPECGROUPDEF_ALIGNMENT 2
#define SUNSPECGROUPDEF_SIZE 12
#define SUNSPECGROUPDEF_UNPADDED_SIZE 12

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *id() const
    {
        const int16_t offset = SUNSPECGROUPDEF_ID_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *count_point_id() const
    {
        const int16_t offset = SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Vector<SunspecPointDef> *points() const
    {
        const int16_t offset = SUNSPECGROUPDEF_POINTS_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Vector<SunspecPointDef> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Vector<SunspecGroupDef> *groups() const
    {
        const int16_t offset = SUNSPECGROUPDEF_GROUPS_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Vector<SunspecGroupDef> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE const ::nakedbytes::Offset<::nakedbytes::String> *label() const
    {
        const int16_t offset = SUNSPECGROUPDEF_LABEL_OFFSET;
        return reinterpret_cast<const ::nakedbytes::Offset<::nakedbytes::String> *>(&data_[offset]);
    }

    NAKEDBYTES_FORCE_INLINE uint8_t count() const
    {
        return *reinterpret_cast<const uint8_t *>(&data_[SUNSPECGROUPDEF_COUNT_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE SunspecGroupType type() const
    {
        return *reinterpret_cast<const SunspecGroupType *>(&data_[SUNSPECGROUPDEF_TYPE_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 12;

private:
    SunspecGroupDef() = delete;
    SunspecGroupDef(const SunspecGroupDef &) = delete;
    SunspecGroupDef &operator=(const SunspecGroupDef &) = delete;
    unsigned char data_[1];
};

struct SunspecModelDef
{

#define SUNSPECMODELDEF_ID_OFFSET 0
#define SUNSPECMODELDEF_GROUP_OFFSET 2
#define SUNSPECMODELDEF_ALIGNMENT 2
#define SUNSPECMODELDEF_SIZE 14
#define SUNSPECMODELDEF_UNPADDED_SIZE 14

    NAKEDBYTES_FORCE_INLINE uint16_t id() const
    {
        return *reinterpret_cast<const uint16_t *>(&data_[SUNSPECMODELDEF_ID_OFFSET]);
    }

    NAKEDBYTES_FORCE_INLINE const SunspecGroupDef &group() const
    {
        return *reinterpret_cast<const SunspecGroupDef *>(&data_[SUNSPECMODELDEF_GROUP_OFFSET]);
    }

    static constexpr uint16_t nakedbytes_sizeof = 14;

private:
    SunspecModelDef() = delete;
    SunspecModelDef(const SunspecModelDef &) = delete;
    SunspecModelDef &operator=(const SunspecModelDef &) = delete;
    unsigned char data_[1];
};

const SunspecModelDef *GetRootSunspecModelDef(const unsigned char *const buffer)
{
    return reinterpret_cast<const SunspecModelDef *>(&buffer[2 * OFFSET_SIZE + ::nakedbytes::get_padding_size((2 * OFFSET_SIZE), SUNSPECMODELDEF_ALIGNMENT)]);
}

namespace nakedbytes
{
    template <typename T>
    struct SerializeOffset
    {
        // Offset relative to the start of the buffer
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

        unsigned char *_buffer = nullptr;
        uint16_t _buffer_size = 0;
        // uint16_t _current_offset = 0;
        uint16_t _tail_offset = 0;

        void init(uint16_t buffer_size, const uint16_t root_type_size, uint16_t root_type_alignment)
        {
            _buffer = static_cast<unsigned char *>(malloc(buffer_size));
            _buffer_size = buffer_size;
            *reinterpret_cast<uint16_t *>(&_buffer[OFFSET_SIZE]) = VERSION;

            _tail_offset = static_cast<uint16_t>(static_cast<uint16_t>(get_padding_size(OFFSET_SIZE * 2, root_type_alignment)) + static_cast<uint16_t>(OFFSET_SIZE) * 2 + static_cast<uint16_t>(root_type_size));
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
                uint16_t len = static_cast<uint16_t>(strlen(str));
                _tail_offset += static_cast<uint16_t>(get_padding_size(_tail_offset, OFFSET_SIZE));

                make_buffer_adequate();
                str_offset.offset = _tail_offset;

                *reinterpret_cast<uint16_t *>(&_buffer[_tail_offset]) = len;
                _tail_offset += OFFSET_SIZE;
                memcpy(&_buffer[_tail_offset], str, len);
                *reinterpret_cast<unsigned char *>(&(((unsigned char *)_buffer)[_tail_offset + len])) = 0;
                _tail_offset += static_cast<uint16_t>(len + 1);
            }
            return str_offset;
        }

        template <typename T>
        typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_enum<T>::value), SerializeOffset<T>>::type serialize_primitive(T data)
        {
            SerializeOffset<T> data_offset;
            _tail_offset += static_cast<uint16_t>(get_padding_size(_tail_offset, sizeof(T)));

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
            uint16_t len = static_cast<uint16_t>(data_array.size());
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
            uint16_t len = static_cast<uint16_t>(data_array.size());
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

struct Enum64Struct
{
    uint64_t value;
};

struct Acc16Struct
{
    uint16_t value;
};

struct Float32Struct
{
    float value;
};

struct Uint64Struct
{
    uint64_t value;
};

struct Sint64Struct
{
    int64_t value;
};

struct Eui48Struct
{
    uint16_t value0;
    uint16_t value1;
    uint16_t value2;
};

struct Float64Struct
{
    double value;
};

struct SunspecPointData_enumStruct
{
};

struct SunspecPointDataStruct
{
};

struct SunspecPointAccessStruct
{
};

struct SunspecPointMandatoryStruct
{
};

struct SunspecPointDefStruct
{
    ::nakedbytes::SerializeOffset<::nakedbytes::String> id;
    ::nakedbytes::SerializeOffset<::nakedbytes::String> sf_id;
    ::nakedbytes::SerializeOffset<::nakedbytes::String> units;
    ::nakedbytes::SerializeOffset<::nakedbytes::String> label;
    SunspecPointData_enum data_type;
    ::nakedbytes::SerializeOffset<void> data;
    uint8_t count;
    ::nakedbytes::SerializeOffset<::nakedbytes::String> count_point_id;
    uint8_t size;
    int8_t sf;
    SunspecPointAccess access;
    SunspecPointMandatory mandatory;
};

struct SunspecGroupTypeStruct
{
};

struct SunspecGroupDefStruct
{
    ::nakedbytes::SerializeOffset<::nakedbytes::String> id;
    ::nakedbytes::SerializeOffset<::nakedbytes::String> count_point_id;
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecPointDefStruct>> points;
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecGroupDefStruct>> groups;
    ::nakedbytes::SerializeOffset<::nakedbytes::String> label;
    uint8_t count;
    SunspecGroupType type;
};

struct Pad16Struct
{
    uint16_t value;
};

struct Enum16Struct
{
    uint16_t value;
};

struct SunspecModelDefStruct
{
    uint16_t id;
    SunspecGroupDefStruct group;
};

struct Enum32Struct
{
    uint32_t value;
};

struct StringxStruct
{
    ::nakedbytes::SerializeOffset<::nakedbytes::String> value;
};

struct Bitfield16Struct
{
    uint16_t value;
};

struct Bitfield32Struct
{
    uint32_t value;
};

struct Bitfield64Struct
{
    uint64_t value;
};

struct SunsSfStruct
{
    uint16_t value;
};

struct Uint16Struct
{
    uint16_t value;
};

struct Acc32Struct
{
    uint32_t value;
};

struct Sint32Struct
{
    int32_t value;
};

struct Ipv6AddrStruct
{
    uint8_t octet0;
    uint8_t octet1;
    uint8_t octet2;
    uint8_t octet3;
    uint8_t octet4;
    uint8_t octet5;
};

struct Acc64Struct
{
    uint64_t value;
};

struct IpAddrStruct
{
    uint8_t octet1;
    uint8_t octet2;
    uint8_t octet3;
    uint8_t octet4;
};

struct Uint32Struct
{
    uint32_t value;
};

struct Sint16Struct
{
    int16_t value;
};

struct Raw16Struct
{
    uint16_t value;
};

inline ::nakedbytes::SerializeOffset<Enum64> serialize_enum64(::nakedbytes::Serializer *const serializer,
                                                              const uint64_t value)
{
    ::nakedbytes::SerializeOffset<Enum64> enum64_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ENUM64_ALIGNMENT);
    serializer->make_buffer_adequate();
    enum64_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + ENUM64_VALUE_OFFSET])) = static_cast<uint64_t>(value);
    serializer->_tail_offset += ENUM64_SIZE;
    return enum64_offset;
}

inline ::nakedbytes::SerializeOffset<Acc16> serialize_acc16(::nakedbytes::Serializer *const serializer,
                                                            const uint16_t value)
{
    ::nakedbytes::SerializeOffset<Acc16> acc16_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ACC16_ALIGNMENT);
    serializer->make_buffer_adequate();
    acc16_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + ACC16_VALUE_OFFSET])) = static_cast<uint16_t>(value);
    serializer->_tail_offset += ACC16_SIZE;
    return acc16_offset;
}

inline ::nakedbytes::SerializeOffset<Float32> serialize_float32(::nakedbytes::Serializer *const serializer,
                                                                const float value)
{
    ::nakedbytes::SerializeOffset<Float32> float32_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, FLOAT32_ALIGNMENT);
    serializer->make_buffer_adequate();
    float32_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset + FLOAT32_VALUE_OFFSET])) = static_cast<float>(value);
    serializer->_tail_offset += FLOAT32_SIZE;
    return float32_offset;
}

inline ::nakedbytes::SerializeOffset<Uint64> serialize_uint64(::nakedbytes::Serializer *const serializer,
                                                              const uint64_t value)
{
    ::nakedbytes::SerializeOffset<Uint64> uint64_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, UINT64_ALIGNMENT);
    serializer->make_buffer_adequate();
    uint64_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + UINT64_VALUE_OFFSET])) = static_cast<uint64_t>(value);
    serializer->_tail_offset += UINT64_SIZE;
    return uint64_offset;
}

inline ::nakedbytes::SerializeOffset<Sint64> serialize_sint64(::nakedbytes::Serializer *const serializer,
                                                              const int64_t value)
{
    ::nakedbytes::SerializeOffset<Sint64> sint64_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SINT64_ALIGNMENT);
    serializer->make_buffer_adequate();
    sint64_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + SINT64_VALUE_OFFSET])) = static_cast<int64_t>(value);
    serializer->_tail_offset += SINT64_SIZE;
    return sint64_offset;
}

inline ::nakedbytes::SerializeOffset<Eui48> serialize_eui48(::nakedbytes::Serializer *const serializer,
                                                            const uint16_t value0,
                                                            const uint16_t value1,
                                                            const uint16_t value2)
{
    ::nakedbytes::SerializeOffset<Eui48> eui48_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, EUI48_ALIGNMENT);
    serializer->make_buffer_adequate();
    eui48_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + EUI48_VALUE0_OFFSET])) = static_cast<uint16_t>(value0);
    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + EUI48_VALUE1_OFFSET])) = static_cast<uint16_t>(value1);
    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + EUI48_VALUE2_OFFSET])) = static_cast<uint16_t>(value2);
    serializer->_tail_offset += EUI48_SIZE;
    return eui48_offset;
}

inline ::nakedbytes::SerializeOffset<Float64> serialize_float64(::nakedbytes::Serializer *const serializer,
                                                                const double value)
{
    ::nakedbytes::SerializeOffset<Float64> float64_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, FLOAT64_ALIGNMENT);
    serializer->make_buffer_adequate();
    float64_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<double *>(&(serializer->_buffer[serializer->_tail_offset + FLOAT64_VALUE_OFFSET])) = static_cast<double>(value);
    serializer->_tail_offset += FLOAT64_SIZE;
    return float64_offset;
}

inline ::nakedbytes::SerializeOffset<SunspecGroupDef> serialize_sunspecgroupdef(::nakedbytes::Serializer *const serializer,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> id,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> count_point_id,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecPointDefStruct>> points,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecGroupDefStruct>> groups,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> label,
                                                                                const uint8_t count,
                                                                                const SunspecGroupType type)
{
    ::nakedbytes::SerializeOffset<SunspecGroupDef> sunspecgroupdef_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECGROUPDEF_ALIGNMENT);
    serializer->make_buffer_adequate();
    sunspecgroupdef_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECGROUPDEF_ID_OFFSET])) = static_cast<int16_t>(id.offset - (serializer->_tail_offset + SUNSPECGROUPDEF_ID_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET])) = static_cast<int16_t>(count_point_id.offset - (serializer->_tail_offset + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECGROUPDEF_POINTS_OFFSET])) = static_cast<int16_t>(points.offset - (serializer->_tail_offset + SUNSPECGROUPDEF_POINTS_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECGROUPDEF_GROUPS_OFFSET])) = static_cast<int16_t>(groups.offset - (serializer->_tail_offset + SUNSPECGROUPDEF_GROUPS_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECGROUPDEF_LABEL_OFFSET])) = static_cast<int16_t>(label.offset - (serializer->_tail_offset + SUNSPECGROUPDEF_LABEL_OFFSET));
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECGROUPDEF_COUNT_OFFSET])) = static_cast<uint8_t>(count);
    *reinterpret_cast<SunspecGroupType *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECGROUPDEF_TYPE_OFFSET])) = static_cast<SunspecGroupType>(type);
    serializer->_tail_offset += SUNSPECGROUPDEF_SIZE;
    return sunspecgroupdef_offset;
}

inline ::nakedbytes::SerializeOffset<Pad16> serialize_pad16(::nakedbytes::Serializer *const serializer,
                                                            const uint16_t value)
{
    ::nakedbytes::SerializeOffset<Pad16> pad16_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, PAD16_ALIGNMENT);
    serializer->make_buffer_adequate();
    pad16_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + PAD16_VALUE_OFFSET])) = static_cast<uint16_t>(value);
    serializer->_tail_offset += PAD16_SIZE;
    return pad16_offset;
}

inline ::nakedbytes::SerializeOffset<Enum16> serialize_enum16(::nakedbytes::Serializer *const serializer,
                                                              const uint16_t value)
{
    ::nakedbytes::SerializeOffset<Enum16> enum16_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ENUM16_ALIGNMENT);
    serializer->make_buffer_adequate();
    enum16_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + ENUM16_VALUE_OFFSET])) = static_cast<uint16_t>(value);
    serializer->_tail_offset += ENUM16_SIZE;
    return enum16_offset;
}

inline ::nakedbytes::SerializeOffset<SunspecModelDef> serialize_sunspecmodeldef(::nakedbytes::Serializer *const serializer,
                                                                                const uint16_t id,
                                                                                const SunspecGroupDefStruct group)
{
    ::nakedbytes::SerializeOffset<SunspecModelDef> sunspecmodeldef_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECMODELDEF_ALIGNMENT);
    serializer->make_buffer_adequate();
    sunspecmodeldef_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_ID_OFFSET])) = static_cast<uint16_t>(id);

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET])) = static_cast<int16_t>(group.id.offset - (serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET])) = static_cast<int16_t>(group.count_point_id.offset - (serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_POINTS_OFFSET])) = static_cast<int16_t>(group.points.offset - (serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_POINTS_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_GROUPS_OFFSET])) = static_cast<int16_t>(group.groups.offset - (serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_GROUPS_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_LABEL_OFFSET])) = static_cast<int16_t>(group.label.offset - (serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_LABEL_OFFSET));
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_OFFSET])) = static_cast<uint8_t>(group.count);
    *reinterpret_cast<SunspecGroupType *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_TYPE_OFFSET])) = static_cast<SunspecGroupType>(group.type);
    serializer->_tail_offset += SUNSPECMODELDEF_SIZE;
    return sunspecmodeldef_offset;
}

inline ::nakedbytes::SerializeOffset<Enum32> serialize_enum32(::nakedbytes::Serializer *const serializer,
                                                              const uint32_t value)
{
    ::nakedbytes::SerializeOffset<Enum32> enum32_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ENUM32_ALIGNMENT);
    serializer->make_buffer_adequate();
    enum32_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + ENUM32_VALUE_OFFSET])) = static_cast<uint32_t>(value);
    serializer->_tail_offset += ENUM32_SIZE;
    return enum32_offset;
}

inline ::nakedbytes::SerializeOffset<Stringx> serialize_stringx(::nakedbytes::Serializer *const serializer,
                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> value)
{
    ::nakedbytes::SerializeOffset<Stringx> stringx_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, STRINGX_ALIGNMENT);
    serializer->make_buffer_adequate();
    stringx_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + STRINGX_VALUE_OFFSET])) = static_cast<int16_t>(value.offset - (serializer->_tail_offset + STRINGX_VALUE_OFFSET));
    serializer->_tail_offset += STRINGX_SIZE;
    return stringx_offset;
}

inline ::nakedbytes::SerializeOffset<Bitfield16> serialize_bitfield16(::nakedbytes::Serializer *const serializer,
                                                                      const uint16_t value)
{
    ::nakedbytes::SerializeOffset<Bitfield16> bitfield16_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, BITFIELD16_ALIGNMENT);
    serializer->make_buffer_adequate();
    bitfield16_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + BITFIELD16_VALUE_OFFSET])) = static_cast<uint16_t>(value);
    serializer->_tail_offset += BITFIELD16_SIZE;
    return bitfield16_offset;
}

inline ::nakedbytes::SerializeOffset<SunspecPointDef> serialize_sunspecpointdef(::nakedbytes::Serializer *const serializer,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> id,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> sf_id,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> units,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> label,
                                                                                const SunspecPointData_enum data_type,
                                                                                const ::nakedbytes::SerializeOffset<void> data,
                                                                                const uint8_t count,
                                                                                const ::nakedbytes::SerializeOffset<::nakedbytes::String> count_point_id,
                                                                                const uint8_t size,
                                                                                const int8_t sf,
                                                                                const SunspecPointAccess access,
                                                                                const SunspecPointMandatory mandatory)
{
    ::nakedbytes::SerializeOffset<SunspecPointDef> sunspecpointdef_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECPOINTDEF_ALIGNMENT);
    serializer->make_buffer_adequate();
    sunspecpointdef_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_ID_OFFSET])) = static_cast<int16_t>(id.offset - (serializer->_tail_offset + SUNSPECPOINTDEF_ID_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_SF_ID_OFFSET])) = static_cast<int16_t>(sf_id.offset - (serializer->_tail_offset + SUNSPECPOINTDEF_SF_ID_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_UNITS_OFFSET])) = static_cast<int16_t>(units.offset - (serializer->_tail_offset + SUNSPECPOINTDEF_UNITS_OFFSET));
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_LABEL_OFFSET])) = static_cast<int16_t>(label.offset - (serializer->_tail_offset + SUNSPECPOINTDEF_LABEL_OFFSET));
    *reinterpret_cast<SunspecPointData_enum *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_DATA_TYPE_OFFSET])) = static_cast<SunspecPointData_enum>(data_type);
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_DATA_OFFSET])) = static_cast<int16_t>(data.offset - (serializer->_tail_offset + SUNSPECPOINTDEF_DATA_OFFSET));
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_COUNT_OFFSET])) = static_cast<uint8_t>(count);
    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_COUNT_POINT_ID_OFFSET])) = static_cast<int16_t>(count_point_id.offset - (serializer->_tail_offset + SUNSPECPOINTDEF_COUNT_POINT_ID_OFFSET));
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_SIZE_OFFSET])) = static_cast<uint8_t>(size);
    *reinterpret_cast<int8_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_SF_OFFSET])) = static_cast<int8_t>(sf);
    *reinterpret_cast<SunspecPointAccess *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_ACCESS_OFFSET])) = static_cast<SunspecPointAccess>(access);
    *reinterpret_cast<SunspecPointMandatory *>(&(serializer->_buffer[serializer->_tail_offset + SUNSPECPOINTDEF_MANDATORY_OFFSET])) = static_cast<SunspecPointMandatory>(mandatory);
    serializer->_tail_offset += SUNSPECPOINTDEF_SIZE;
    return sunspecpointdef_offset;
}

inline ::nakedbytes::SerializeOffset<Bitfield32> serialize_bitfield32(::nakedbytes::Serializer *const serializer,
                                                                      const uint32_t value)
{
    ::nakedbytes::SerializeOffset<Bitfield32> bitfield32_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, BITFIELD32_ALIGNMENT);
    serializer->make_buffer_adequate();
    bitfield32_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + BITFIELD32_VALUE_OFFSET])) = static_cast<uint32_t>(value);
    serializer->_tail_offset += BITFIELD32_SIZE;
    return bitfield32_offset;
}

inline ::nakedbytes::SerializeOffset<Bitfield64> serialize_bitfield64(::nakedbytes::Serializer *const serializer,
                                                                      const uint64_t value)
{
    ::nakedbytes::SerializeOffset<Bitfield64> bitfield64_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, BITFIELD64_ALIGNMENT);
    serializer->make_buffer_adequate();
    bitfield64_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + BITFIELD64_VALUE_OFFSET])) = static_cast<uint64_t>(value);
    serializer->_tail_offset += BITFIELD64_SIZE;
    return bitfield64_offset;
}

inline ::nakedbytes::SerializeOffset<SunsSf> serialize_sunssf(::nakedbytes::Serializer *const serializer,
                                                              const uint16_t value)
{
    ::nakedbytes::SerializeOffset<SunsSf> sunssf_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSSF_ALIGNMENT);
    serializer->make_buffer_adequate();
    sunssf_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + SUNSSF_VALUE_OFFSET])) = static_cast<uint16_t>(value);
    serializer->_tail_offset += SUNSSF_SIZE;
    return sunssf_offset;
}

inline ::nakedbytes::SerializeOffset<Uint16> serialize_uint16(::nakedbytes::Serializer *const serializer,
                                                              const uint16_t value)
{
    ::nakedbytes::SerializeOffset<Uint16> uint16_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, UINT16_ALIGNMENT);
    serializer->make_buffer_adequate();
    uint16_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + UINT16_VALUE_OFFSET])) = static_cast<uint16_t>(value);
    serializer->_tail_offset += UINT16_SIZE;
    return uint16_offset;
}

inline ::nakedbytes::SerializeOffset<Acc32> serialize_acc32(::nakedbytes::Serializer *const serializer,
                                                            const uint32_t value)
{
    ::nakedbytes::SerializeOffset<Acc32> acc32_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ACC32_ALIGNMENT);
    serializer->make_buffer_adequate();
    acc32_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + ACC32_VALUE_OFFSET])) = static_cast<uint32_t>(value);
    serializer->_tail_offset += ACC32_SIZE;
    return acc32_offset;
}

inline ::nakedbytes::SerializeOffset<SunspecPointData> serialize_sunspecpointdata(::nakedbytes::Serializer *const serializer)
{
    ::nakedbytes::SerializeOffset<SunspecPointData> sunspecpointdata_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECPOINTDATA_ALIGNMENT);
    serializer->make_buffer_adequate();
    sunspecpointdata_offset.offset = serializer->_tail_offset;

    serializer->_tail_offset += SUNSPECPOINTDATA_SIZE;
    return sunspecpointdata_offset;
}

inline ::nakedbytes::SerializeOffset<Sint32> serialize_sint32(::nakedbytes::Serializer *const serializer,
                                                              const int32_t value)
{
    ::nakedbytes::SerializeOffset<Sint32> sint32_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SINT32_ALIGNMENT);
    serializer->make_buffer_adequate();
    sint32_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int32_t *>(&(serializer->_buffer[serializer->_tail_offset + SINT32_VALUE_OFFSET])) = static_cast<int32_t>(value);
    serializer->_tail_offset += SINT32_SIZE;
    return sint32_offset;
}

inline ::nakedbytes::SerializeOffset<Ipv6Addr> serialize_ipv6addr(::nakedbytes::Serializer *const serializer,
                                                                  const uint8_t octet0,
                                                                  const uint8_t octet1,
                                                                  const uint8_t octet2,
                                                                  const uint8_t octet3,
                                                                  const uint8_t octet4,
                                                                  const uint8_t octet5)
{
    ::nakedbytes::SerializeOffset<Ipv6Addr> ipv6addr_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, IPV6ADDR_ALIGNMENT);
    serializer->make_buffer_adequate();
    ipv6addr_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPV6ADDR_OCTET0_OFFSET])) = static_cast<uint8_t>(octet0);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPV6ADDR_OCTET1_OFFSET])) = static_cast<uint8_t>(octet1);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPV6ADDR_OCTET2_OFFSET])) = static_cast<uint8_t>(octet2);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPV6ADDR_OCTET3_OFFSET])) = static_cast<uint8_t>(octet3);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPV6ADDR_OCTET4_OFFSET])) = static_cast<uint8_t>(octet4);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPV6ADDR_OCTET5_OFFSET])) = static_cast<uint8_t>(octet5);
    serializer->_tail_offset += IPV6ADDR_SIZE;
    return ipv6addr_offset;
}

inline ::nakedbytes::SerializeOffset<Acc64> serialize_acc64(::nakedbytes::Serializer *const serializer,
                                                            const uint64_t value)
{
    ::nakedbytes::SerializeOffset<Acc64> acc64_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ACC64_ALIGNMENT);
    serializer->make_buffer_adequate();
    acc64_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + ACC64_VALUE_OFFSET])) = static_cast<uint64_t>(value);
    serializer->_tail_offset += ACC64_SIZE;
    return acc64_offset;
}

inline ::nakedbytes::SerializeOffset<IpAddr> serialize_ipaddr(::nakedbytes::Serializer *const serializer,
                                                              const uint8_t octet1,
                                                              const uint8_t octet2,
                                                              const uint8_t octet3,
                                                              const uint8_t octet4)
{
    ::nakedbytes::SerializeOffset<IpAddr> ipaddr_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, IPADDR_ALIGNMENT);
    serializer->make_buffer_adequate();
    ipaddr_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPADDR_OCTET1_OFFSET])) = static_cast<uint8_t>(octet1);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPADDR_OCTET2_OFFSET])) = static_cast<uint8_t>(octet2);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPADDR_OCTET3_OFFSET])) = static_cast<uint8_t>(octet3);
    *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + IPADDR_OCTET4_OFFSET])) = static_cast<uint8_t>(octet4);
    serializer->_tail_offset += IPADDR_SIZE;
    return ipaddr_offset;
}

inline ::nakedbytes::SerializeOffset<Uint32> serialize_uint32(::nakedbytes::Serializer *const serializer,
                                                              const uint32_t value)
{
    ::nakedbytes::SerializeOffset<Uint32> uint32_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, UINT32_ALIGNMENT);
    serializer->make_buffer_adequate();
    uint32_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + UINT32_VALUE_OFFSET])) = static_cast<uint32_t>(value);
    serializer->_tail_offset += UINT32_SIZE;
    return uint32_offset;
}

inline ::nakedbytes::SerializeOffset<Sint16> serialize_sint16(::nakedbytes::Serializer *const serializer,
                                                              const int16_t value)
{
    ::nakedbytes::SerializeOffset<Sint16> sint16_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SINT16_ALIGNMENT);
    serializer->make_buffer_adequate();
    sint16_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + SINT16_VALUE_OFFSET])) = static_cast<int16_t>(value);
    serializer->_tail_offset += SINT16_SIZE;
    return sint16_offset;
}

inline ::nakedbytes::SerializeOffset<Raw16> serialize_raw16(::nakedbytes::Serializer *const serializer,
                                                            const uint16_t value)
{
    ::nakedbytes::SerializeOffset<Raw16> raw16_offset;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, RAW16_ALIGNMENT);
    serializer->make_buffer_adequate();
    raw16_offset.offset = serializer->_tail_offset;

    *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + RAW16_VALUE_OFFSET])) = static_cast<uint16_t>(value);
    serializer->_tail_offset += RAW16_SIZE;
    return raw16_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Enum64Struct>> serialize_vector_enum64_struct(::nakedbytes::Serializer *const serializer, std::vector<Enum64Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Enum64Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ENUM64_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + (ENUM64_SIZE * i) + ENUM64_VALUE_OFFSET])) = static_cast<uint64_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(ENUM64_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Acc16Struct>> serialize_vector_acc16_struct(::nakedbytes::Serializer *const serializer, std::vector<Acc16Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Acc16Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ACC16_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (ACC16_SIZE * i) + ACC16_VALUE_OFFSET])) = static_cast<uint16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(ACC16_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Float32Struct>> serialize_vector_float32_struct(::nakedbytes::Serializer *const serializer, std::vector<Float32Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Float32Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, FLOAT32_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<float *>(&(serializer->_buffer[serializer->_tail_offset + (FLOAT32_SIZE * i) + FLOAT32_VALUE_OFFSET])) = static_cast<float>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(FLOAT32_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Uint64Struct>> serialize_vector_uint64_struct(::nakedbytes::Serializer *const serializer, std::vector<Uint64Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Uint64Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, UINT64_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + (UINT64_SIZE * i) + UINT64_VALUE_OFFSET])) = static_cast<uint64_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(UINT64_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Sint64Struct>> serialize_vector_sint64_struct(::nakedbytes::Serializer *const serializer, std::vector<Sint64Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Sint64Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SINT64_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int64_t *>(&(serializer->_buffer[serializer->_tail_offset + (SINT64_SIZE * i) + SINT64_VALUE_OFFSET])) = static_cast<int64_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(SINT64_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Eui48Struct>> serialize_vector_eui48_struct(::nakedbytes::Serializer *const serializer, std::vector<Eui48Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Eui48Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, EUI48_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (EUI48_SIZE * i) + EUI48_VALUE0_OFFSET])) = static_cast<uint16_t>(data_array[i].value0);
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (EUI48_SIZE * i) + EUI48_VALUE1_OFFSET])) = static_cast<uint16_t>(data_array[i].value1);
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (EUI48_SIZE * i) + EUI48_VALUE2_OFFSET])) = static_cast<uint16_t>(data_array[i].value2);
        serializer->_tail_offset += static_cast<uint16_t>(EUI48_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Float64Struct>> serialize_vector_float64_struct(::nakedbytes::Serializer *const serializer, std::vector<Float64Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Float64Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, FLOAT64_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<double *>(&(serializer->_buffer[serializer->_tail_offset + (FLOAT64_SIZE * i) + FLOAT64_VALUE_OFFSET])) = static_cast<double>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(FLOAT64_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecGroupDefStruct>> serialize_vector_sunspecgroupdef_struct(::nakedbytes::Serializer *const serializer, std::vector<SunspecGroupDefStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecGroupDefStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECGROUPDEF_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_ID_OFFSET])) = static_cast<int16_t>(data_array[i].id.offset - (serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET])) = static_cast<int16_t>(data_array[i].count_point_id.offset - (serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_POINTS_OFFSET])) = static_cast<int16_t>(data_array[i].points.offset - (serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_POINTS_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_GROUPS_OFFSET])) = static_cast<int16_t>(data_array[i].groups.offset - (serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_GROUPS_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_LABEL_OFFSET])) = static_cast<int16_t>(data_array[i].label.offset - (serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_LABEL_OFFSET));
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_COUNT_OFFSET])) = static_cast<uint8_t>(data_array[i].count);
        *reinterpret_cast<SunspecGroupType *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECGROUPDEF_SIZE * i) + SUNSPECGROUPDEF_TYPE_OFFSET])) = static_cast<SunspecGroupType>(data_array[i].type);
        serializer->_tail_offset += static_cast<uint16_t>(SUNSPECGROUPDEF_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Pad16Struct>> serialize_vector_pad16_struct(::nakedbytes::Serializer *const serializer, std::vector<Pad16Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Pad16Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, PAD16_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (PAD16_SIZE * i) + PAD16_VALUE_OFFSET])) = static_cast<uint16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(PAD16_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Enum16Struct>> serialize_vector_enum16_struct(::nakedbytes::Serializer *const serializer, std::vector<Enum16Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Enum16Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ENUM16_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (ENUM16_SIZE * i) + ENUM16_VALUE_OFFSET])) = static_cast<uint16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(ENUM16_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecModelDefStruct>> serialize_vector_sunspecmodeldef_struct(::nakedbytes::Serializer *const serializer, std::vector<SunspecModelDefStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecModelDefStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECMODELDEF_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_ID_OFFSET])) = static_cast<uint16_t>(data_array[i].id);

        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET])) = static_cast<int16_t>(data_array[i].group.id.offset - (serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET])) = static_cast<int16_t>(data_array[i].group.count_point_id.offset - (serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_POINTS_OFFSET])) = static_cast<int16_t>(data_array[i].group.points.offset - (serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_POINTS_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_GROUPS_OFFSET])) = static_cast<int16_t>(data_array[i].group.groups.offset - (serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_GROUPS_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_LABEL_OFFSET])) = static_cast<int16_t>(data_array[i].group.label.offset - (serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_LABEL_OFFSET));
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_OFFSET])) = static_cast<uint8_t>(data_array[i].group.count);
        *reinterpret_cast<SunspecGroupType *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECMODELDEF_SIZE * i) + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_TYPE_OFFSET])) = static_cast<SunspecGroupType>(data_array[i].group.type);
        serializer->_tail_offset += static_cast<uint16_t>(SUNSPECMODELDEF_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Enum32Struct>> serialize_vector_enum32_struct(::nakedbytes::Serializer *const serializer, std::vector<Enum32Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Enum32Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ENUM32_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + (ENUM32_SIZE * i) + ENUM32_VALUE_OFFSET])) = static_cast<uint32_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(ENUM32_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<StringxStruct>> serialize_vector_stringx_struct(::nakedbytes::Serializer *const serializer, std::vector<StringxStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<StringxStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, STRINGX_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (STRINGX_SIZE * i) + STRINGX_VALUE_OFFSET])) = static_cast<int16_t>(data_array[i].value.offset - (serializer->_tail_offset + (STRINGX_SIZE * i) + STRINGX_VALUE_OFFSET));
        serializer->_tail_offset += static_cast<uint16_t>(STRINGX_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Bitfield16Struct>> serialize_vector_bitfield16_struct(::nakedbytes::Serializer *const serializer, std::vector<Bitfield16Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Bitfield16Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, BITFIELD16_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (BITFIELD16_SIZE * i) + BITFIELD16_VALUE_OFFSET])) = static_cast<uint16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(BITFIELD16_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecPointDefStruct>> serialize_vector_sunspecpointdef_struct(::nakedbytes::Serializer *const serializer, std::vector<SunspecPointDefStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecPointDefStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECPOINTDEF_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_ID_OFFSET])) = static_cast<int16_t>(data_array[i].id.offset - (serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_SF_ID_OFFSET])) = static_cast<int16_t>(data_array[i].sf_id.offset - (serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_SF_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_UNITS_OFFSET])) = static_cast<int16_t>(data_array[i].units.offset - (serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_UNITS_OFFSET));
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_LABEL_OFFSET])) = static_cast<int16_t>(data_array[i].label.offset - (serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_LABEL_OFFSET));
        *reinterpret_cast<SunspecPointData_enum *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_DATA_TYPE_OFFSET])) = static_cast<SunspecPointData_enum>(data_array[i].data_type);
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_DATA_OFFSET])) = static_cast<int16_t>(data_array[i].data.offset - (serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_DATA_OFFSET));
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_COUNT_OFFSET])) = static_cast<uint8_t>(data_array[i].count);
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_COUNT_POINT_ID_OFFSET])) = static_cast<int16_t>(data_array[i].count_point_id.offset - (serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_COUNT_POINT_ID_OFFSET));
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_SIZE_OFFSET])) = static_cast<uint8_t>(data_array[i].size);
        *reinterpret_cast<int8_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_SF_OFFSET])) = static_cast<int8_t>(data_array[i].sf);
        *reinterpret_cast<SunspecPointAccess *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_ACCESS_OFFSET])) = static_cast<SunspecPointAccess>(data_array[i].access);
        *reinterpret_cast<SunspecPointMandatory *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSPECPOINTDEF_SIZE * i) + SUNSPECPOINTDEF_MANDATORY_OFFSET])) = static_cast<SunspecPointMandatory>(data_array[i].mandatory);
        serializer->_tail_offset += static_cast<uint16_t>(SUNSPECPOINTDEF_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Bitfield32Struct>> serialize_vector_bitfield32_struct(::nakedbytes::Serializer *const serializer, std::vector<Bitfield32Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Bitfield32Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, BITFIELD32_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + (BITFIELD32_SIZE * i) + BITFIELD32_VALUE_OFFSET])) = static_cast<uint32_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(BITFIELD32_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Bitfield64Struct>> serialize_vector_bitfield64_struct(::nakedbytes::Serializer *const serializer, std::vector<Bitfield64Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Bitfield64Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, BITFIELD64_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + (BITFIELD64_SIZE * i) + BITFIELD64_VALUE_OFFSET])) = static_cast<uint64_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(BITFIELD64_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunsSfStruct>> serialize_vector_sunssf_struct(::nakedbytes::Serializer *const serializer, std::vector<SunsSfStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunsSfStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSSF_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SUNSSF_SIZE * i) + SUNSSF_VALUE_OFFSET])) = static_cast<uint16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(SUNSSF_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Uint16Struct>> serialize_vector_uint16_struct(::nakedbytes::Serializer *const serializer, std::vector<Uint16Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Uint16Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, UINT16_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (UINT16_SIZE * i) + UINT16_VALUE_OFFSET])) = static_cast<uint16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(UINT16_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Acc32Struct>> serialize_vector_acc32_struct(::nakedbytes::Serializer *const serializer, std::vector<Acc32Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Acc32Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ACC32_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + (ACC32_SIZE * i) + ACC32_VALUE_OFFSET])) = static_cast<uint32_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(ACC32_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecPointDataStruct>> serialize_vector_sunspecpointdata_struct(::nakedbytes::Serializer *const serializer, std::vector<SunspecPointDataStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<SunspecPointDataStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SUNSPECPOINTDATA_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        serializer->_tail_offset += static_cast<uint16_t>(SUNSPECPOINTDATA_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Sint32Struct>> serialize_vector_sint32_struct(::nakedbytes::Serializer *const serializer, std::vector<Sint32Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Sint32Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SINT32_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int32_t *>(&(serializer->_buffer[serializer->_tail_offset + (SINT32_SIZE * i) + SINT32_VALUE_OFFSET])) = static_cast<int32_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(SINT32_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Ipv6AddrStruct>> serialize_vector_ipv6addr_struct(::nakedbytes::Serializer *const serializer, std::vector<Ipv6AddrStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Ipv6AddrStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, IPV6ADDR_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPV6ADDR_SIZE * i) + IPV6ADDR_OCTET0_OFFSET])) = static_cast<uint8_t>(data_array[i].octet0);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPV6ADDR_SIZE * i) + IPV6ADDR_OCTET1_OFFSET])) = static_cast<uint8_t>(data_array[i].octet1);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPV6ADDR_SIZE * i) + IPV6ADDR_OCTET2_OFFSET])) = static_cast<uint8_t>(data_array[i].octet2);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPV6ADDR_SIZE * i) + IPV6ADDR_OCTET3_OFFSET])) = static_cast<uint8_t>(data_array[i].octet3);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPV6ADDR_SIZE * i) + IPV6ADDR_OCTET4_OFFSET])) = static_cast<uint8_t>(data_array[i].octet4);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPV6ADDR_SIZE * i) + IPV6ADDR_OCTET5_OFFSET])) = static_cast<uint8_t>(data_array[i].octet5);
        serializer->_tail_offset += static_cast<uint16_t>(IPV6ADDR_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Acc64Struct>> serialize_vector_acc64_struct(::nakedbytes::Serializer *const serializer, std::vector<Acc64Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Acc64Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, ACC64_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint64_t *>(&(serializer->_buffer[serializer->_tail_offset + (ACC64_SIZE * i) + ACC64_VALUE_OFFSET])) = static_cast<uint64_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(ACC64_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<IpAddrStruct>> serialize_vector_ipaddr_struct(::nakedbytes::Serializer *const serializer, std::vector<IpAddrStruct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<IpAddrStruct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, IPADDR_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPADDR_SIZE * i) + IPADDR_OCTET1_OFFSET])) = static_cast<uint8_t>(data_array[i].octet1);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPADDR_SIZE * i) + IPADDR_OCTET2_OFFSET])) = static_cast<uint8_t>(data_array[i].octet2);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPADDR_SIZE * i) + IPADDR_OCTET3_OFFSET])) = static_cast<uint8_t>(data_array[i].octet3);
        *reinterpret_cast<uint8_t *>(&(serializer->_buffer[serializer->_tail_offset + (IPADDR_SIZE * i) + IPADDR_OCTET4_OFFSET])) = static_cast<uint8_t>(data_array[i].octet4);
        serializer->_tail_offset += static_cast<uint16_t>(IPADDR_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Uint32Struct>> serialize_vector_uint32_struct(::nakedbytes::Serializer *const serializer, std::vector<Uint32Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Uint32Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, UINT32_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint32_t *>(&(serializer->_buffer[serializer->_tail_offset + (UINT32_SIZE * i) + UINT32_VALUE_OFFSET])) = static_cast<uint32_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(UINT32_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Sint16Struct>> serialize_vector_sint16_struct(::nakedbytes::Serializer *const serializer, std::vector<Sint16Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Sint16Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, SINT16_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<int16_t *>(&(serializer->_buffer[serializer->_tail_offset + (SINT16_SIZE * i) + SINT16_VALUE_OFFSET])) = static_cast<int16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(SINT16_SIZE * len);
    }
    return data_array_offset;
}

inline ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Raw16Struct>> serialize_vector_raw16_struct(::nakedbytes::Serializer *const serializer, std::vector<Raw16Struct> data_array)
{
    ::nakedbytes::SerializeOffset<::nakedbytes::Vector<Raw16Struct>> data_array_offset;
    uint16_t len = static_cast<uint16_t>(data_array.size());
    serializer->_tail_offset += static_cast<uint16_t>(::nakedbytes::get_padding_size(serializer->_tail_offset, OFFSET_SIZE));
    serializer->make_buffer_adequate();
    data_array_offset.offset = serializer->_tail_offset;
    *reinterpret_cast<uint16_t *>(&serializer->_buffer[serializer->_tail_offset]) = len;
    serializer->_tail_offset += OFFSET_SIZE;
    serializer->_tail_offset += ::nakedbytes::get_padding_size(serializer->_tail_offset, RAW16_ALIGNMENT);
    for (uint16_t i = 0; i < len; i++)
    {
        *reinterpret_cast<uint16_t *>(&(serializer->_buffer[serializer->_tail_offset + (RAW16_SIZE * i) + RAW16_VALUE_OFFSET])) = static_cast<uint16_t>(data_array[i].value);
        serializer->_tail_offset += static_cast<uint16_t>(RAW16_SIZE * len);
    }
    return data_array_offset;
}

struct SunspecModelDefSerializer : public ::nakedbytes::Serializer
{
    void init(uint16_t buffer_size)
    {
        ::nakedbytes::Serializer::init(buffer_size, SUNSPECMODELDEF_SIZE, SUNSPECMODELDEF_ALIGNMENT);
    }

    inline uint16_t serialize_root(
        const uint16_t id,
        const SunspecGroupDefStruct group)
    {
        uint16_t current_offset = static_cast<uint16_t>(OFFSET_SIZE * 2 + ::nakedbytes::get_padding_size(OFFSET_SIZE * 2, SUNSPECMODELDEF_ALIGNMENT));
        *reinterpret_cast<uint16_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_ID_OFFSET])) = static_cast<uint16_t>(id);

        *reinterpret_cast<int16_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET])) = static_cast<int16_t>(group.id.offset - (current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET])) = static_cast<int16_t>(group.count_point_id.offset - (current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_POINT_ID_OFFSET));
        *reinterpret_cast<int16_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_POINTS_OFFSET])) = static_cast<int16_t>(group.points.offset - (current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_POINTS_OFFSET));
        *reinterpret_cast<int16_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_GROUPS_OFFSET])) = static_cast<int16_t>(group.groups.offset - (current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_GROUPS_OFFSET));
        *reinterpret_cast<int16_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_LABEL_OFFSET])) = static_cast<int16_t>(group.label.offset - (current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_LABEL_OFFSET));
        *reinterpret_cast<uint8_t *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_COUNT_OFFSET])) = static_cast<uint8_t>(group.count);
        *reinterpret_cast<SunspecGroupType *>(&(this->_buffer[current_offset + SUNSPECMODELDEF_GROUP_OFFSET + SUNSPECGROUPDEF_TYPE_OFFSET])) = static_cast<SunspecGroupType>(group.type);

        *reinterpret_cast<uint16_t *>(&(this->_buffer[0])) = this->_tail_offset;

        return this->_tail_offset;
    }
};

#endif //__SUNSPEC_MODEL_STRUCT_OFFSET_NAKEDBYTES_GENERATED_H