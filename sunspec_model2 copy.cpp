#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "model1_2.h"

#define OFFSET_SIZE 2

struct SunspecModel;
struct SunspecGroupPoint;
struct SunspecPoint;

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
        int16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *value()
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data) == 0;
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
        int offset = DATA_OFFSET + *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]);

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
        int offset = OFFSET_SIZE + index * OFFSET_SIZE;

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
        return *reinterpret_cast<uint16_t *>(model_) == 0;
    }
#define POINT_ID_OFFSET 0
    StringOffset id()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_ID_OFFSET;
        return StringOffset(&model_[offset]);
    }
#define POINT_SF_ID_OFFSET 2
    StringOffset sf_id()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_SF_ID_OFFSET;

        return StringOffset(&model_[offset]);
    }
#define POINT_UNITS_OFFSET 4
    const char *units()
    {
        int offset = *reinterpret_cast<uint16_t *>(model_) + POINT_UNITS_OFFSET + *reinterpret_cast<uint16_t *>(&model_[POINT_UNITS_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model_[offset]);
    }
#define POINT_LABEL_OFFSET 6
    const char *label()
    {
        int offset = *reinterpret_cast<uint16_t *>(model_);
        offset += POINT_LABEL_OFFSET + *reinterpret_cast<uint16_t *>(&model_[POINT_LABEL_OFFSET + offset]);
        offset += OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model_[offset]);
    }

#define POINT_DATA_OFFSET 8
    Union<SunspecPointData> data()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_DATA_OFFSET;
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
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_COUNT_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_SIZE_OFFSET 13
    uint8_t size()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_SIZE_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_SF_OFFSET 14
    int8_t sf()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_SF_OFFSET;

        return *reinterpret_cast<int8_t *>(&model_[offset]);
    }

#define POINT_ACCESS_OFFSET 15
    uint8_t access()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_ACCESS_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }

#define POINT_MANDATORY_OFFSET 16
    uint8_t mandatory()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(model_) + POINT_MANDATORY_OFFSET;

        return *reinterpret_cast<uint8_t *>(&model_[offset]);
    }
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

        int offset = ID_OFFSET + *reinterpret_cast<uint16_t *>(&model_[ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model_[offset]);
    }

#define COUNT_POINT_ID_OFFSET 2
    const char *count_point_id()
    {

        int offset = COUNT_POINT_ID_OFFSET + *reinterpret_cast<uint16_t *>(&model_[COUNT_POINT_ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model_[offset]);
    }

#define POINTS_OFFSET 4
    Vector<SunspecPoint> points()
    {
        int offset = POINTS_OFFSET + *reinterpret_cast<uint16_t *>(&model_[POINTS_OFFSET]);
        Vector<SunspecPoint> vec{&model_[offset]};
        return vec;
    }

#define GROUPS_OFFSET 6
    Vector<SunspecGroupPoint> groups()
    {
        int offset = GROUPS_OFFSET + *reinterpret_cast<uint16_t *>(&model_[GROUPS_OFFSET]);
        Vector<SunspecGroupPoint> vec{&model_[offset]};
        return vec;
    }
#define LABEL_OFFSET 8
    const char *label()
    {
        int offset = LABEL_OFFSET + *reinterpret_cast<uint16_t *>(&model_[LABEL_OFFSET]) + OFFSET_SIZE;
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
        int offset = GROUP_OFFSET + *reinterpret_cast<uint16_t *>(&model_[GROUP_OFFSET]);
        return SunspecGroupPoint(&model_[offset]);
    }
#define MODEL_ROOT_LENGTH_OFFSET 4
};

template <typename T>
struct Offset
{

    unsigned char *data;
    Offset(unsigned char *dataPtr)
    {
        data = dataPtr;
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
        uint16_t offset =  STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *value()
    {
        uint16_t offset = STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
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


    Offset<String_Unoffset> serialize_string(const char *str){
        int str_length = strlen(str);
        int total_size = OFFSET_SIZE + str_length + 1; 
        if (remaining_space() < total_size)
        {
            // Not enough space
            return Offset<String_Unoffset>(nullptr);
        }
       
        // Write length
        *reinterpret_cast<uint16_t *>(&buffer_[current_offset_]) = str_length;
        current_offset_ += OFFSET_SIZE;
        // Write string value
        memcpy(&buffer_[current_offset_], str, str_length + 1);
        current_offset_ += str_length + 1;
        Offset<String_Unoffset> offset(&buffer_[current_offset_ - OFFSET_SIZE - (str_length + 1)]);
        return offset;
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
        printf("  Units: %s\n", point.units());
        printf("  Label: %s\n", point.label());
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
    return 0;
}