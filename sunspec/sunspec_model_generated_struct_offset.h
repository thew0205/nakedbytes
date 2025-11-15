
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define OFFSET_SIZE 2

struct bitfield16;
struct eui48;
struct pad;
struct SunspecModelDef;
struct SunspecModelDefOffset;
struct enum16;
struct enum32;
struct SunspecPointDef;
struct SunspecPointDefOffset;
struct SunspecGroupPointDef;
struct SunspecGroupPointDefOffset;
struct enum64;
struct bitfield32;
struct bitfield64;
struct sunssf;
struct acc16;
struct acc32;
struct acc64;
struct SunspecPointData;
struct SunspecPointDataOffset;
struct ipaddr;
struct ipv6addr;

struct StringOffset
{
    unsigned char *data;
    StringOffset(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define STRING_LENGTH_OFFSET 0
    uint16_t length()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *value()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
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
    uint16_t type()
    {
        return *reinterpret_cast<uint16_t *>(&data[UNION_TYPE_OFFSET]);
    }

#define DATA_OFFSET 2
    unsigned char *raw_data()
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) + DATA_OFFSET;

        return (&data[offset]);
    }

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) == 0;
    }
};

template <typename T>
struct Vector
{
    unsigned char *data;

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }

    uint16_t size()
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index)
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + OFFSET_SIZE * index;

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};

struct bitfield16
{

    unsigned char *data_;

    bitfield16(unsigned char *data) : data_(data) {}

#define BITFIELD16_VALUE_OFFSET 0

    uint16_t value() { return *reinterpret_cast<uint16_t *>(&data_[BITFIELD16_VALUE_OFFSET]); }
};

struct eui48
{

    unsigned char *data_;

    eui48(unsigned char *data) : data_(data) {}

#define EUI48_VALUE0_OFFSET 0
#define EUI48_VALUE1_OFFSET 2
#define EUI48_VALUE2_OFFSET 4

    uint16_t value0() { return *reinterpret_cast<uint16_t *>(&data_[EUI48_VALUE0_OFFSET]); }

    uint16_t value1() { return *reinterpret_cast<uint16_t *>(&data_[EUI48_VALUE1_OFFSET]); }

    uint16_t value2() { return *reinterpret_cast<uint16_t *>(&data_[EUI48_VALUE2_OFFSET]); }
};

enum SunspecPointMandatoryType : uint8_t
{

    SunspecPointMandatoryType_kM,
    SunspecPointMandatoryType_kO,
};

const char *SunspecPointMandatoryType_to_string(SunspecPointMandatoryType value)
{
    switch (value)
    {
    case SunspecPointMandatoryType_kM:
        return "SunspecPointMandatoryType_kM";
    case SunspecPointMandatoryType_kO:
        return "SunspecPointMandatoryType_kO";
    default:
        return NULL;
    }
}

struct pad
{

    unsigned char *data_;

    pad(unsigned char *data) : data_(data) {}

#define PAD_VALUE_OFFSET 0

    uint16_t value() { return *reinterpret_cast<uint16_t *>(&data_[PAD_VALUE_OFFSET]); }
};

enum SunspecPointAccessType : uint8_t
{

    SunspecPointAccessType_kR,
    SunspecPointAccessType_kRW,
};

const char *SunspecPointAccessType_to_string(SunspecPointAccessType value)
{
    switch (value)
    {
    case SunspecPointAccessType_kR:
        return "SunspecPointAccessType_kR";
    case SunspecPointAccessType_kRW:
        return "SunspecPointAccessType_kRW";
    default:
        return NULL;
    }
}

enum SunspecPointData_enum : uint16_t
{

    SunspecPointData_enum_uint16,
    SunspecPointData_enum_int16,
    SunspecPointData_enum_uint32,
    SunspecPointData_enum_int32,
    SunspecPointData_enum_uint64,
    SunspecPointData_enum_int64,
    SunspecPointData_enum_float32,
    SunspecPointData_enum_float64,
    SunspecPointData_enum_string,
    SunspecPointData_enum_pad,
    SunspecPointData_enum_enum16,
    SunspecPointData_enum_enum32,
    SunspecPointData_enum_enum64,
    SunspecPointData_enum_bitfield16,
    SunspecPointData_enum_bitfield32,
    SunspecPointData_enum_bitfield64,
    SunspecPointData_enum_sunssf,
    SunspecPointData_enum_acc16,
    SunspecPointData_enum_acc32,
    SunspecPointData_enum_acc64,
    SunspecPointData_enum_eui48,
    SunspecPointData_enum_ipaddr,
    SunspecPointData_enum_ipv6addr,
};

const char *SunspecPointData_enum_to_string(SunspecPointData_enum value)
{
    switch (value)
    {
    case SunspecPointData_enum_uint16:
        return "SunspecPointData_enum_uint16";
    case SunspecPointData_enum_int16:
        return "SunspecPointData_enum_int16";
    case SunspecPointData_enum_uint32:
        return "SunspecPointData_enum_uint32";
    case SunspecPointData_enum_int32:
        return "SunspecPointData_enum_int32";
    case SunspecPointData_enum_uint64:
        return "SunspecPointData_enum_uint64";
    case SunspecPointData_enum_int64:
        return "SunspecPointData_enum_int64";
    case SunspecPointData_enum_float32:
        return "SunspecPointData_enum_float32";
    case SunspecPointData_enum_float64:
        return "SunspecPointData_enum_float64";
    case SunspecPointData_enum_string:
        return "SunspecPointData_enum_string";
    case SunspecPointData_enum_pad:
        return "SunspecPointData_enum_pad";
    case SunspecPointData_enum_enum16:
        return "SunspecPointData_enum_enum16";
    case SunspecPointData_enum_enum32:
        return "SunspecPointData_enum_enum32";
    case SunspecPointData_enum_enum64:
        return "SunspecPointData_enum_enum64";
    case SunspecPointData_enum_bitfield16:
        return "SunspecPointData_enum_bitfield16";
    case SunspecPointData_enum_bitfield32:
        return "SunspecPointData_enum_bitfield32";
    case SunspecPointData_enum_bitfield64:
        return "SunspecPointData_enum_bitfield64";
    case SunspecPointData_enum_sunssf:
        return "SunspecPointData_enum_sunssf";
    case SunspecPointData_enum_acc16:
        return "SunspecPointData_enum_acc16";
    case SunspecPointData_enum_acc32:
        return "SunspecPointData_enum_acc32";
    case SunspecPointData_enum_acc64:
        return "SunspecPointData_enum_acc64";
    case SunspecPointData_enum_eui48:
        return "SunspecPointData_enum_eui48";
    case SunspecPointData_enum_ipaddr:
        return "SunspecPointData_enum_ipaddr";
    case SunspecPointData_enum_ipv6addr:
        return "SunspecPointData_enum_ipv6addr";
    default:
        return NULL;
    }
}

struct SunspecPointDef
{

    unsigned char *data_;

    SunspecPointDef(unsigned char *data) : data_(data) {}

#define SUNSPECPOINTDEF_ID_OFFSET 0
#define SUNSPECPOINTDEF_SF_ID_OFFSET 2
#define SUNSPECPOINTDEF_UNITS_OFFSET 4
#define SUNSPECPOINTDEF_LABEL_OFFSET 6
#define SUNSPECPOINTDEF_DATA_TYPE_OFFSET 8
#define SUNSPECPOINTDEF_DATA_OFFSET 10
#define SUNSPECPOINTDEF_COUNT_OFFSET 12
#define SUNSPECPOINTDEF_SIZE_OFFSET 13
#define SUNSPECPOINTDEF_SF_OFFSET 14
#define SUNSPECPOINTDEF_ACCESS_OFFSET 15
#define SUNSPECPOINTDEF_MANDATORY_OFFSET 16
#define SUNSPECPOINTDEF_PAD17_OFFSET 17

    StringOffset id()
    {
        const int16_t offset = SUNSPECPOINTDEF_ID_OFFSET;
        return StringOffset(&data_[offset]);
    }

    StringOffset sf_id()
    {
        const int16_t offset = SUNSPECPOINTDEF_SF_ID_OFFSET;
        return StringOffset(&data_[offset]);
    }

    StringOffset units()
    {
        const int16_t offset = SUNSPECPOINTDEF_UNITS_OFFSET;
        return StringOffset(&data_[offset]);
    }

    StringOffset label()
    {
        const int16_t offset = SUNSPECPOINTDEF_LABEL_OFFSET;
        return StringOffset(&data_[offset]);
    }

    SunspecPointData_enum data_type() { return *reinterpret_cast<SunspecPointData_enum *>(&data_[SUNSPECPOINTDEF_DATA_TYPE_OFFSET]); }

    Union<SunspecPointData> data()
    {
        const int16_t offset = SUNSPECPOINTDEF_DATA_OFFSET - 2;
        return Union<SunspecPointData>(&data_[offset]);
    }

    uint8_t count() { return *reinterpret_cast<uint8_t *>(&data_[SUNSPECPOINTDEF_COUNT_OFFSET]); }

    uint8_t size() { return *reinterpret_cast<uint8_t *>(&data_[SUNSPECPOINTDEF_SIZE_OFFSET]); }

    int8_t sf() { return *reinterpret_cast<int8_t *>(&data_[SUNSPECPOINTDEF_SF_OFFSET]); }

    SunspecPointAccessType access() { return *reinterpret_cast<SunspecPointAccessType *>(&data_[SUNSPECPOINTDEF_ACCESS_OFFSET]); }

    SunspecPointMandatoryType mandatory() { return *reinterpret_cast<SunspecPointMandatoryType *>(&data_[SUNSPECPOINTDEF_MANDATORY_OFFSET]); }
};

struct SunspecPointDefOffset
{

    unsigned char *data_;

    SunspecPointDefOffset(unsigned char *data) : data_(data) {}

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }

    SunspecPointDef value()
    {
        const int16_t offset = *reinterpret_cast<int16_t *>(data_);
        return SunspecPointDef(&data_[offset]);
    }
};
enum SunspecGroupType : uint8_t
{

    SunspecGroupType_kGroup,
    SunspecGroupType_kSync,
};

const char *SunspecGroupType_to_string(SunspecGroupType value)
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

struct SunspecGroupPointDef
{

    unsigned char *data_;

    SunspecGroupPointDef(unsigned char *data) : data_(data) {}

#define SUNSPECGROUPPOINTDEF_ID_OFFSET 0
#define SUNSPECGROUPPOINTDEF_COUNT_POINT_ID_OFFSET 2
#define SUNSPECGROUPPOINTDEF_POINTS_OFFSET 4
#define SUNSPECGROUPPOINTDEF_GROUPS_OFFSET 6
#define SUNSPECGROUPPOINTDEF_LABEL_OFFSET 8
#define SUNSPECGROUPPOINTDEF_COUNT_OFFSET 10
#define SUNSPECGROUPPOINTDEF_TYPE_OFFSET 11

    StringOffset id()
    {
        const int16_t offset = SUNSPECGROUPPOINTDEF_ID_OFFSET;
        return StringOffset(&data_[offset]);
    }

    StringOffset count_point_id()
    {
        const int16_t offset = SUNSPECGROUPPOINTDEF_COUNT_POINT_ID_OFFSET;
        return StringOffset(&data_[offset]);
    }

    Vector<SunspecPointDefOffset> points()
    {
        const int16_t offset = SUNSPECGROUPPOINTDEF_POINTS_OFFSET;
        return Vector<SunspecPointDefOffset>(&data_[offset]);
    }

    Vector<SunspecGroupPointDefOffset> groups()
    {
        const int16_t offset = SUNSPECGROUPPOINTDEF_GROUPS_OFFSET;
        return Vector<SunspecGroupPointDefOffset>(&data_[offset]);
    }

    StringOffset label()
    {
        const int16_t offset = SUNSPECGROUPPOINTDEF_LABEL_OFFSET;
        return StringOffset(&data_[offset]);
    }

    uint8_t count() { return *reinterpret_cast<uint8_t *>(&data_[SUNSPECGROUPPOINTDEF_COUNT_OFFSET]); }

    SunspecGroupType type() { return *reinterpret_cast<SunspecGroupType *>(&data_[SUNSPECGROUPPOINTDEF_TYPE_OFFSET]); }
};

struct SunspecGroupPointDefOffset
{

    unsigned char *data_;

    SunspecGroupPointDefOffset(unsigned char *data) : data_(data) {}

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }

    SunspecGroupPointDef value()
    {
        const int16_t offset = *reinterpret_cast<int16_t *>(data_);
        return SunspecGroupPointDef(&data_[offset]);
    }
};

struct SunspecModelDef
{

    unsigned char *data_;

    SunspecModelDef(unsigned char *data) : data_(data) {}

#define SUNSPECMODELDEF_ID_OFFSET 0
#define SUNSPECMODELDEF_GROUP_OFFSET 2

    uint16_t id() { return *reinterpret_cast<uint16_t *>(&data_[SUNSPECMODELDEF_ID_OFFSET + 2 * OFFSET_SIZE]); }

    SunspecGroupPointDefOffset group()
    {
        const int16_t offset = SUNSPECMODELDEF_GROUP_OFFSET + 2 * OFFSET_SIZE;
        return SunspecGroupPointDefOffset(&data_[offset]);
    }
};

struct SunspecModelDefOffset
{

    unsigned char *data_;

    SunspecModelDefOffset(unsigned char *data) : data_(data) {}

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }

    SunspecModelDef value()
    {
        const int16_t offset = *reinterpret_cast<int16_t *>(data_);
        return SunspecModelDef(&data_[offset]);
    }
};

struct enum16
{

    unsigned char *data_;

    enum16(unsigned char *data) : data_(data) {}

#define ENUM16_VALUE_OFFSET 0

    uint16_t value() { return *reinterpret_cast<uint16_t *>(&data_[ENUM16_VALUE_OFFSET]); }
};

struct enum32
{

    unsigned char *data_;

    enum32(unsigned char *data) : data_(data) {}

#define ENUM32_VALUE_OFFSET 0

    uint32_t value() { return *reinterpret_cast<uint32_t *>(&data_[ENUM32_VALUE_OFFSET]); }
};

struct enum64
{

    unsigned char *data_;

    enum64(unsigned char *data) : data_(data) {}

#define ENUM64_VALUE_OFFSET 0

    uint64_t value() { return *reinterpret_cast<uint64_t *>(&data_[ENUM64_VALUE_OFFSET]); }
};

struct bitfield32
{

    unsigned char *data_;

    bitfield32(unsigned char *data) : data_(data) {}

#define BITFIELD32_VALUE_OFFSET 0

    uint32_t value() { return *reinterpret_cast<uint32_t *>(&data_[BITFIELD32_VALUE_OFFSET]); }
};

struct bitfield64
{

    unsigned char *data_;

    bitfield64(unsigned char *data) : data_(data) {}

#define BITFIELD64_VALUE_OFFSET 0

    uint64_t value() { return *reinterpret_cast<uint64_t *>(&data_[BITFIELD64_VALUE_OFFSET]); }
};

struct sunssf
{

    unsigned char *data_;

    sunssf(unsigned char *data) : data_(data) {}

#define SUNSSF_VALUE_OFFSET 0

    uint16_t value() { return *reinterpret_cast<uint16_t *>(&data_[SUNSSF_VALUE_OFFSET]); }
};

struct acc16
{

    unsigned char *data_;

    acc16(unsigned char *data) : data_(data) {}

#define ACC16_VALUE_OFFSET 0

    uint16_t value() { return *reinterpret_cast<uint16_t *>(&data_[ACC16_VALUE_OFFSET]); }
};

struct acc32
{

    unsigned char *data_;

    acc32(unsigned char *data) : data_(data) {}

#define ACC32_VALUE_OFFSET 0

    uint32_t value() { return *reinterpret_cast<uint32_t *>(&data_[ACC32_VALUE_OFFSET]); }
};

struct acc64
{

    unsigned char *data_;

    acc64(unsigned char *data) : data_(data) {}

#define ACC64_VALUE_OFFSET 0

    uint64_t value() { return *reinterpret_cast<uint64_t *>(&data_[ACC64_VALUE_OFFSET]); }
};

struct ipaddr
{

    unsigned char *data_;

    ipaddr(unsigned char *data) : data_(data) {}

#define IPADDR_VALUE0_OFFSET 0
#define IPADDR_VALUE1_OFFSET 2
#define IPADDR_VALUE2_OFFSET 4
#define IPADDR_VALUE3_OFFSET 6

    uint16_t value0() { return *reinterpret_cast<uint16_t *>(&data_[IPADDR_VALUE0_OFFSET]); }

    uint16_t value1() { return *reinterpret_cast<uint16_t *>(&data_[IPADDR_VALUE1_OFFSET]); }

    uint16_t value2() { return *reinterpret_cast<uint16_t *>(&data_[IPADDR_VALUE2_OFFSET]); }

    uint16_t value3() { return *reinterpret_cast<uint16_t *>(&data_[IPADDR_VALUE3_OFFSET]); }
};

struct ipv6addr
{

    unsigned char *data_;

    ipv6addr(unsigned char *data) : data_(data) {}

#define IPV6ADDR_VALUE0_OFFSET 0
#define IPV6ADDR_VALUE1_OFFSET 2
#define IPV6ADDR_VALUE2_OFFSET 4
#define IPV6ADDR_VALUE3_OFFSET 6
#define IPV6ADDR_VALUE4_OFFSET 8
#define IPV6ADDR_VALUE5_OFFSET 10

    uint16_t value0() { return *reinterpret_cast<uint16_t *>(&data_[IPV6ADDR_VALUE0_OFFSET]); }

    uint16_t value1() { return *reinterpret_cast<uint16_t *>(&data_[IPV6ADDR_VALUE1_OFFSET]); }

    uint16_t value2() { return *reinterpret_cast<uint16_t *>(&data_[IPV6ADDR_VALUE2_OFFSET]); }

    uint16_t value3() { return *reinterpret_cast<uint16_t *>(&data_[IPV6ADDR_VALUE3_OFFSET]); }

    uint16_t value4() { return *reinterpret_cast<uint16_t *>(&data_[IPV6ADDR_VALUE4_OFFSET]); }

    uint16_t value5() { return *reinterpret_cast<uint16_t *>(&data_[IPV6ADDR_VALUE5_OFFSET]); }
};
