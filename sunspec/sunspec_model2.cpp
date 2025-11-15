#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "model1_2.h"

#define OFFSET_SIZE 2

struct SunspecModel;
struct SunspecGroupPoint;
struct SunspecPoint;

int get_padding_size(int offset, int alignment)
{
    return (alignment - (offset % alignment)) % alignment;
}

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
        int16_t offset = *reinterpret_cast<int16_t *>(data) + STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *value()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(data) + STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }

    bool is_null()
    {
        return *reinterpret_cast<int16_t *>(data) == 0;
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
        int offset = DATA_OFFSET + *reinterpret_cast<int16_t *>(&data[DATA_OFFSET]);

        return (&data[offset]);
    }
};

template <typename T>
struct Vector
{
    unsigned char *data;

    uint16_t size()
    {
        return *reinterpret_cast<uint16_t *>(&data[0]);
    }

    T get(size_t index)
    {
        int16_t offset = OFFSET_SIZE + index * OFFSET_SIZE;
        // offset = *reinterpret_cast<uint16_t *>(&data[offset]) + offset;

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};

struct SunspecPointData
{
    /* data */
};

struct SunspecPoint
{
    unsigned char *model_;

    SunspecPoint(unsigned char *model)
    {
        model_ = model;
    }

    bool is_null()
    {
        return *reinterpret_cast<int16_t *>(model_) == 0;
    }
#define POINT_ID_OFFSET 0
    StringOffset id()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_ID_OFFSET;
        return StringOffset(&model_[offset]);
    }
#define POINT_SF_ID_OFFSET 2
    StringOffset sf_id()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_SF_ID_OFFSET;

        return StringOffset(&model_[offset]);
    }
#define POINT_UNITS_OFFSET 4
    StringOffset units()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_UNITS_OFFSET;
        return StringOffset(&model_[offset]);
    }
#define POINT_LABEL_OFFSET 6
    StringOffset label()
    {
        int offset = *reinterpret_cast<int16_t *>(model_) + POINT_LABEL_OFFSET;

        return StringOffset(&model_[offset]);
    }

#define POINT_DATA_OFFSET 8
    Union<SunspecPointData> data()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_DATA_OFFSET;
        return Union<SunspecPointData>(&model_[offset]);
    }

    // #define POINT_DATA_TYPE_OFFSET 8
    //     uint16_t data_type()
    //     {
    //         return *reinterpret_cast<uint16_t *>(&model_[POINT_DATA_TYPE_OFFSET]);
    //     }

    // #define POINT_DATA_OFFSET 10

#define POINT_COUNT_OFFSET 12
    uint8_t count()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_COUNT_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_SIZE_OFFSET 13
    uint8_t size()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_SIZE_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_SF_OFFSET 14
    int8_t sf()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_SF_OFFSET;

        return *reinterpret_cast<int8_t *>(&model_[offset]);
    }

#define POINT_ACCESS_OFFSET 15
    uint8_t access()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_ACCESS_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_MANDATORY_OFFSET 16
    uint8_t mandatory()
    {
        int16_t offset = *reinterpret_cast<int16_t *>(model_) + POINT_MANDATORY_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }
#define POINT_ROOT_LENGTH_OFFSET 18
};

struct SunspecGroupPoint
{
    unsigned char *model_;

    SunspecGroupPoint(unsigned char *model)
    {
        model_ = model;
    }

#define ID_OFFSET 0
    const char *id()
    {

        int offset = ID_OFFSET + *reinterpret_cast<int16_t *>(&model_[ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model_[offset]);
    }

#define COUNT_POINT_ID_OFFSET 2
    const char *count_point_id()
    {

        int offset = COUNT_POINT_ID_OFFSET + *reinterpret_cast<int16_t *>(&model_[COUNT_POINT_ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model_[offset]);
    }

#define POINTS_OFFSET 4
    Vector<SunspecPoint> points()
    {
        int16_t offset = POINTS_OFFSET + *reinterpret_cast<int16_t *>(&model_[POINTS_OFFSET]);
        Vector<SunspecPoint> vec{&model_[offset]};
        return vec;
    }

#define GROUPS_OFFSET 6
    Vector<SunspecGroupPoint> groups()
    {
        int16_t offset = GROUPS_OFFSET + *reinterpret_cast<int16_t *>(&model_[GROUPS_OFFSET]);
        Vector<SunspecGroupPoint> vec{&model_[offset]};
        return vec;
    }
#define LABEL_OFFSET 8
    const char *label()
    {
        int16_t offset = LABEL_OFFSET + *reinterpret_cast<int16_t *>(&model_[LABEL_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model_[offset]);
    }

#define COUNT_OFFSET 10
    uint8_t count()
    {
        return *reinterpret_cast<uint8_t *>(&model_[COUNT_OFFSET]);
    }

#define TYPE_OFFSET 11
    uint8_t type()
    {
        return *reinterpret_cast<uint8_t *>(&model_[TYPE_OFFSET]);
    }
};

struct SunspecModel
{
    unsigned char *model_;

    SunspecModel(unsigned char *modelDef)
    {
        model_ = modelDef;
    }
#define ID_OFFSET 0
    uint16_t id()
    {
        return *reinterpret_cast<uint16_t *>(&model_[ID_OFFSET]);
    }

#define GROUP_OFFSET 2
    SunspecGroupPoint group()
    {
        int16_t offset = GROUP_OFFSET + *reinterpret_cast<int16_t *>(&model_[GROUP_OFFSET]);
        return SunspecGroupPoint(&model_[offset]);
    }
#define MODEL_ROOT_LENGTH_OFFSET 4
};

template <typename T>
struct Offset
{

    uint16_t size = 0;
    unsigned char *data;
    Offset(unsigned char *dataPtr, uint16_t dataSize)
    {
        data = dataPtr;
        size = dataSize;
    }

    Offset()
    {
        data = nullptr;
        size = 0;
    }
    T get_data()
    {
        return T(data);
    };
};

struct String_Unoffset
{
    unsigned char *data;
    String_Unoffset(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define STRING_LENGTH_OFFSET 0
    uint16_t length()
    {
        int16_t offset = STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *value()
    {
        int16_t offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }
};

struct SunspecPoint_Unoffset
{
    unsigned char *model_;

    SunspecPoint_Unoffset(unsigned char *model)
    {
        model_ = model;
    }

#define POINT_ID_OFFSET 0
    StringOffset id()
    {
        int16_t offset = POINT_ID_OFFSET;
        return StringOffset(&model_[offset]);
    }
#define POINT_SF_ID_OFFSET 2
    StringOffset sf_id()
    {
        int16_t offset = POINT_SF_ID_OFFSET;

        return StringOffset(&model_[offset]);
    }
#define POINT_UNITS_OFFSET 4
    StringOffset units()
    {
        int16_t offset = POINT_UNITS_OFFSET;
        return StringOffset(&model_[offset]);
    }
#define POINT_LABEL_OFFSET 6
    StringOffset label()
    {
        int offset = POINT_LABEL_OFFSET;

        return StringOffset(&model_[offset]);
    }

#define POINT_DATA_OFFSET 8
    Union<SunspecPointData> data()
    {
        int16_t offset = POINT_DATA_OFFSET;
        return Union<SunspecPointData>(&model_[offset]);
    }

    // #define POINT_DATA_TYPE_OFFSET 8
    //     uint16_t data_type()
    //     {
    //         return *reinterpret_cast<uint16_t *>(&model_[POINT_DATA_TYPE_OFFSET]);
    //     }

    // #define POINT_DATA_OFFSET 10

#define POINT_COUNT_OFFSET 12
    uint8_t count()
    {
        int16_t offset = POINT_COUNT_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_SIZE_OFFSET 13
    uint8_t size()
    {
        int16_t offset = POINT_SIZE_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_SF_OFFSET 14
    int8_t sf()
    {
        int16_t offset = POINT_SF_OFFSET;

        return *reinterpret_cast<int8_t *>(&model_[offset]);
    }

#define POINT_ACCESS_OFFSET 15
    uint8_t access()
    {
        int16_t offset = POINT_ACCESS_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_MANDATORY_OFFSET 16
    uint8_t mandatory()
    {
        int16_t offset = POINT_MANDATORY_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }
};

struct SunspecModelSerializer
{
    unsigned char *buffer_{nullptr};
    int buffer_size_{0};
    int current_offset_{0};

    SunspecModelSerializer(int size)
    {
        buffer_ = new unsigned char[size];
        buffer_size_ = size;
        memset(buffer_, 0, size);
        current_offset_ = MODEL_ROOT_LENGTH_OFFSET;
    }

    ~SunspecModelSerializer()
    {
        if (buffer_)
        {
            delete[] buffer_;
            buffer_ = nullptr;
        }
    }

    bool has_space()
    {
        return remaining_space() > 0;
    }

    int remaining_space()
    {
        return buffer_size_ - current_offset_;
    }

    Offset<String_Unoffset> serialize_string(const char *str)
    {
        uint16_t str_length = strlen(str);
        int total_size = OFFSET_SIZE + str_length + 1;
        if (remaining_space() < total_size)
        {
            // Not enough space
            return Offset<String_Unoffset>();
        }

        // Write length
        memcpy(&buffer_[current_offset_], &str_length, OFFSET_SIZE);
        current_offset_ += OFFSET_SIZE;
        // Write string value
        memcpy(&buffer_[current_offset_], str, str_length + 1);
        current_offset_ += str_length + 1;
        Offset<String_Unoffset> offset(&buffer_[current_offset_ - total_size], total_size);
        return offset;
    }

    Offset<SunspecPoint_Unoffset> serialize_point(Offset<String_Unoffset> id, Offset<String_Unoffset> sf_id, Offset<String_Unoffset> units, Offset<String_Unoffset> label, uint16_t data_type, Offset<Union<SunspecPointData>> data, uint8_t count, uint8_t size, int8_t sf, uint8_t access, uint8_t mandatory)
    {
        int total_size = POINT_ROOT_LENGTH_OFFSET;
        if (remaining_space() < total_size)
        {
            // Not enough space
            return Offset<SunspecPoint_Unoffset>();
        }
        memset(&buffer_[current_offset_], 0, total_size);
        // Write ID
        if (id.data != nullptr)
        {

            int16_t id_offset_from_base = id.data - buffer_;
            int16_t id_offset = id_offset_from_base - current_offset_;

            /* code */
            memcpy(&buffer_[current_offset_], &id_offset, OFFSET_SIZE);
        }
            current_offset_ += OFFSET_SIZE;

        if (sf_id.data != nullptr)
        {

            int16_t sf_id_offset_from_base = sf_id.data - buffer_;
            int16_t sf_id_offset = sf_id_offset_from_base - current_offset_;

            /* code */
            memcpy(&buffer_[current_offset_], &sf_id_offset, OFFSET_SIZE);
        }
            current_offset_ += OFFSET_SIZE;

        // Write Units
        if (units.data != nullptr)
        {
            int16_t units_offset_from_base = units.data - buffer_;
            int16_t units_offset = units_offset_from_base - current_offset_;

            /* code */
            memcpy(&buffer_[current_offset_], &units_offset, OFFSET_SIZE);
        }
            current_offset_ += OFFSET_SIZE;

        // Write Label
        if (label.data != nullptr)
        {
            int16_t label_offset_from_base = label.data - buffer_;
            int16_t label_offset = label_offset_from_base - current_offset_;
            /* code */
            memcpy(&buffer_[current_offset_], &label_offset, OFFSET_SIZE);
        }
            current_offset_ += OFFSET_SIZE;

        // Write Data Type
        memcpy(&buffer_[current_offset_], &data_type, OFFSET_SIZE);
        current_offset_ += OFFSET_SIZE;

        // Write Data
        if (data.data != nullptr)
        {
            int16_t data_offset_from_base = data.data - buffer_;
            int16_t data_offset = data_offset_from_base - current_offset_;
            /* code */
            memcpy(&buffer_[current_offset_], &data_offset, OFFSET_SIZE);
        }
            current_offset_ += OFFSET_SIZE;

        // Write Count
        memcpy(&buffer_[current_offset_], &count, sizeof(uint8_t));
        current_offset_ += 1;

        // Write Size
        memcpy(&buffer_[current_offset_], &size, sizeof(uint8_t));
        current_offset_ += 1;

        // Write SF
        memcpy(&buffer_[current_offset_], &sf, sizeof(int8_t));
        current_offset_ += 1;

        // Write Access
        memcpy(&buffer_[current_offset_ + POINT_ACCESS_OFFSET], &access, sizeof(uint8_t));
        current_offset_ += 1;

        // Write Mandatory
        memcpy(&buffer_[current_offset_ + POINT_MANDATORY_OFFSET], &mandatory, sizeof(uint8_t));
        current_offset_ += 1;

        // padding added
        current_offset_ += 1;

        return Offset<SunspecPoint_Unoffset>(&buffer_[current_offset_ - total_size], total_size);
    }
};

int main()
{
    SunspecModel model = {modelDefinition};

    printf("Model ID: %d\n", model.id());
    SunspecGroupPoint group = model.group();
    printf("Group ID: %s\n", group.id());
    printf("Group Count Point ID: %s\n", group.count_point_id());
    printf("Group Label: %s\n", group.label());
    printf("Group Count: %d\n", group.count());
    printf("Group Type: %d\n", group.type());
    int sip = group.points().size();
    printf("Number of Points: %zu\n", sip);
    int sig = group.groups().size();
    printf("Number of Groups: %zu\n", sig);
    // for (size_t i = 0; i < sig; i++)
    // {
    //     printf("Point %zu:\n", i);
    //     SunspecGroupPoint group_i = group.groups().get(i);
    //     printf("\tGroup [%d] ID: %s\n", i, group_i.id());
    //     printf("\tGroup [%d] Count Point ID: %s\n", i, group_i.count_point_id());
    //     printf("\tGroup [%d] Label: %s\n", i, group_i.label());
    //     printf("\tGroup [%d] Count: %d\n", i, group_i.count());
    //     printf("\tGroup [%d] Type: %d\n", i, group_i.type());
    //     int sip = group_i.points().size();
    //     printf("\tGroup [%d] Number of Points: %zu\n", i, group_i.points().size());
    //     int sig = group_i.groups().size();
    //     printf("\tGroup [%d] Number of Groups: %zu\n", i, group_i.groups().size());
    //     for (size_t j = 0; j < group_i.points().size(); j++)
    //     {
    //         printf("\t\tGroup [%d] Point [%d] %zu:\n", i, j);
    //         SunspecPoint point = group_i.points().get(j);
    //         printf("\t\t  ID: %s\n", point.id());
    //         printf("\t\t  SF ID: %s\n", point.sf_id());
    //         printf("\t\t  Units: %s\n", point.units());
    //         printf("\t\t  Label: %s\n", point.label());
    //         printf("\t\t  Data Type: %d\n", point.data().type());
    //         printf("\t\t  Count: %d\n", point.count());
    //         printf("\t\t  Size: %d\n", point.size());
    //         printf("\t\t  SF: %d\n", point.sf());
    //         printf("\t\t  Access: %d\n", point.access());
    //         printf("\t\t  Mandatory: %d\n", point.mandatory());
    //     }
    // }

    for (size_t i = 0; i < sip; i++)
    {
        printf("Point %zu:\n", i);
        SunspecPoint point = group.points().get(i);
        // printf("  ID: %s\n", point.id().value());
        printf("  ID: %s\n", point.id().value());
        printf("  SF ID: %s\n", point.sf_id().value());
        printf("  Units: %s\n", point.units().value());
        printf("  Label: %s\n", point.label().value());
        printf("  Data Type: %d\n", point.data().type());
        printf("  Count: %d\n", point.count());
        printf("  Size: %d\n", point.size());
        printf("  SF: %d\n", point.sf());
        printf("  Access: %d\n", point.access());
        printf("  Mandatory: %d\n", point.mandatory());
        if (point.data().type() == 0)
        {
            printf("  \t\t\tdata is: %d\n", *(uint16_t *)point.data().raw_data());
        }
    }

    SunspecModelSerializer serializer(1024);
    Offset<String_Unoffset> offset = serializer.serialize_string("Hello, SunSpec!");
    if (offset.data != nullptr)
    {
        printf("Serialized string at offset: %p\n", offset.data);
        printf("String Length: %d\n", offset.get_data().length());
        printf("String Value: %s\n", offset.get_data().value());
    }

    Offset<String_Unoffset> offset1 = serializer.serialize_string("Busoye Tolulope!");
    if (offset.data != nullptr)
    {
        printf("Serialized string at offset: %p\n", offset1.data);
        printf("String Length: %d\n", offset1.get_data().length());
        printf("String Value: %s\n", offset1.get_data().value());
    }

    Offset<SunspecPoint_Unoffset> point_offset = serializer.serialize_point(offset, offset1, offset, offset1, 0, Offset<Union<SunspecPointData>>(), 1, 2, 0, 1, 1);
    if (point_offset.data != nullptr)
    {
        SunspecPoint_Unoffset point = point_offset.get_data();
        printf("Serialized Point at offset: %p\n", point_offset.data);
        printf("Point ID: %s\n", point.id().value());
        printf("Point SF ID: %s\n", point.sf_id().value());
        printf("Point Units: %s\n", point.units().value());
        printf("Point Label: %s\n", point.label().value());
        printf("Point Data Type: %d\n", point.data().type());
        printf("Point Count: %d\n", point.count());
        printf("Point Size: %d\n", point.size());
        printf("Point SF: %d\n", point.sf());
        printf("Point Access: %d\n", point.access());
        printf("Point Mandatory: %d\n", point.mandatory());
    }
    return 0;
}