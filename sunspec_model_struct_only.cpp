#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "model1.h"

#define OFFSET_SIZE 2

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
        offset = *reinterpret_cast<uint16_t *>(&data[offset]) + offset;

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};
// StraightTypeDesc(name=SunspecPointDef, members=[
//     'MemberDesc(name=id, type=string, size=2, offset=0, alignment=2)',
//     'MemberDesc(name=sf_id, type=string, size=2, offset=2, alignment=2)',
//     'MemberDesc(name=units, type=string, size=2, offset=4, alignment=2)',
//     'MemberDesc(name=label, type=string, size=2, offset=6, alignment=2)',
//     'MemberDesc(name=data_type, type=SunspecPointData_enum, size=2, offset=8, alignment=2)',
//     'MemberDesc(name=data, type=SunspecPointData, size=2, offset=8, alignment=2)',
//     'MemberDesc(name=count, type=uint8, size=1, offset=10, alignment=1)',
//     'MemberDesc(name=size, type=uint8, size=1, offset=11, alignment=1)',
//     'MemberDesc(name=sf, type=int8, size=1, offset=12, alignment=1)',
//     'MemberDesc(name=access, type=SunspecPointAccessType, size=1, offset=13, alignment=1)',
//     'MemberDesc(name=mandatory, type=SunspecPointMandatoryType, size=1, offset=14, alignment=1)',
//     'MemberDesc(name=pad17, type=pad1, size=1, offset=17, alignment=1)'])
struct SunspecPoint
{
    unsigned char *point;

    SunspecPoint(unsigned char *pointPtr)
    {
        point = pointPtr;
    }

#define POINT_ID_OFFSET 0
    const char *id()
    {
        int offset = POINT_ID_OFFSET + *reinterpret_cast<uint16_t *>(&point[POINT_ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&point[offset]);
    }
#define POINT_SF_ID_OFFSET 2
    const char *sf_id()
    {
        int offset = POINT_SF_ID_OFFSET + *reinterpret_cast<uint16_t *>(&point[POINT_SF_ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&point[offset]);
    }
#define POINT_UNITS_OFFSET 4
    const char *units()
    {
        int offset = POINT_UNITS_OFFSET + *reinterpret_cast<uint16_t *>(&point[POINT_UNITS_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&point[offset]);
    }
#define POINT_LABEL_OFFSET 6
    const char *label()
    {
        int offset = POINT_LABEL_OFFSET + *reinterpret_cast<uint16_t *>(&point[POINT_LABEL_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&point[offset]);
    }

#define POINT_DATA_TYPE_OFFSET 8
    uint16_t data_type()
    {
        return *reinterpret_cast<uint16_t *>(&point[POINT_DATA_TYPE_OFFSET]);
    }

#define POINT_COUNT_OFFSET 10
    uint8_t count()
    {
        return *reinterpret_cast<uint8_t *>(&point[POINT_COUNT_OFFSET]);
    }

#define POINT_SIZE_OFFSET 11
    uint8_t size()
    {
        return *reinterpret_cast<uint8_t *>(&point[POINT_SIZE_OFFSET]);
    }

#define POINT_SF_OFFSET 12
    int8_t sf()
    {
        return *reinterpret_cast<int8_t *>(&point[POINT_SF_OFFSET]);
    }

#define POINT_ACCESS_OFFSET 13
    uint8_t access()
    {
        return *reinterpret_cast<uint8_t *>(&point[POINT_ACCESS_OFFSET]);
    }

#define POINT_MANDATORY_OFFSET 14
    uint8_t mandatory()
    {
        return *reinterpret_cast<uint8_t *>(&point[POINT_MANDATORY_OFFSET]);
    }
};

struct SunspecModel
{
    unsigned char *model;

#define ID_OFFSET 0
    uint16_t id()
    {
        return *reinterpret_cast<uint16_t *>(&model[ID_OFFSET]);
    }
#define GROUP_ID_OFFSET 2
    const char *group_id()
    {

        int offset = GROUP_ID_OFFSET + *reinterpret_cast<uint16_t *>(&model[GROUP_ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model[offset]);
    }

#define GROUP_COUNT_POINT_ID_OFFSET 4
    const char *group_count_point_id()
    {

        int offset = GROUP_COUNT_POINT_ID_OFFSET + *reinterpret_cast<uint16_t *>(&model[GROUP_COUNT_POINT_ID_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model[offset]);
    }

#define GROUP_POINTS_OFFSET 6
    Vector<SunspecPoint> group_points()
    {
        int offset = GROUP_POINTS_OFFSET + *reinterpret_cast<uint16_t *>(&model[GROUP_COUNT_POINT_ID_OFFSET]);
        Vector<SunspecPoint> vec{&model[offset]};
        return vec;
    }

#define GROUP_LABEL_OFFSET 10
    const char *group_label()
    {
        int offset = GROUP_LABEL_OFFSET + *reinterpret_cast<uint16_t *>(&model[GROUP_LABEL_OFFSET]) + OFFSET_SIZE;
        return reinterpret_cast<const char *>(&model[offset]);
    }

#define GROUP_COUNT_OFFSET 12
    uint8_t group_count()
    {
        return *reinterpret_cast<uint8_t *>(&model[GROUP_COUNT_OFFSET]);
    }

#define GROUP_TYPE_OFFSET 13
    uint8_t group_type()
    {
        return *reinterpret_cast<uint8_t *>(&model[GROUP_TYPE_OFFSET]);
    }
    SunspecModel(unsigned char *modelDef)
    {
        model = modelDef;
    }
};

// StraightTypeDesc(name=SunspecModelDef, members=[
//     'MemberDesc(name=id, type=uint16, size=2, offset=0, alignment=2)',
//     'MemberDesc(name=group::id, type=string, size=2, offset=2, alignment=2)',
//     'MemberDesc(name=group::count_point_id, type=string, size=2, offset=4, alignment=2)',
//     'MemberDesc(name=group::points, type=List[SunspecPointDef], size=2, offset=6, alignment=2)',
//     'MemberDesc(name=group::groups, type=List[SunspecGroupPointDef], size=2, offset=8, alignment=2)',
//     'MemberDesc(name=group::label, type=string, size=2, offset=10, alignment=2)',
//     'MemberDesc(name=group::count, type=uint8, size=1, offset=12, alignment=1)',
//     'MemberDesc(name=group::type, type=SunspecGroupType, size=1, offset=13, alignment=1)'])
int main()
{
    SunspecModel model = {modelDefinition};

    printf("Model ID: %d\n", model.id());
    printf("Group ID: %s\n", model.group_id());
    printf("Group Count Point ID: %s\n", model.group_count_point_id());
    printf("Group Label: %s\n", model.group_label());
    printf("Group Count: %d\n", model.group_count());
    printf("Group Type: %d\n", model.group_type());
    int si = model.group_points().size();
    printf("Number of Points: %zu\n", si);
    for (size_t i = 0; i < si; i++)
    {
        printf("Point %zu:\n", i);
        SunspecPoint point = model.group_points().get(i);
        printf("  ID: %s\n", point.id());
        printf("  SF ID: %s\n", point.sf_id());
        printf("  Units: %s\n", point.units());
        printf("  Label: %s\n", point.label());
        printf("  Data Type: %d\n", point.data_type());
        printf("  Count: %d\n", point.count());
        printf("  Size: %d\n", point.size());
        printf("  SF: %d\n", point.sf());
        printf("  Access: %d\n", point.access());
        printf("  Mandatory: %d\n", point.mandatory());
    }

    return 0;
}