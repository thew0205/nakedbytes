#include "sunspec_model_generated_struct_offset.h"
#include "model_struct_offset_1.h"
int main()
{
    SunspecModelDef model = {modelDefinition};

    printf("Model ID: %d\n", model.id());
    const SunspecGroupPointDef group = model.group().value();
    printf("Group ID: %s\n", group.id().value().c_str());
    printf("Group Count Point ID: %s\n", group.count_point_id().value().c_str());
    printf("Group Label: %s\n", group.label().value().c_str());
    printf("Group Count: %d\n", group.count());
    // printf("Group Type: %d\n", group.type());
    int sip = group.points().size();
    printf("Number of Points: %zu\n", sip);
    int sig = group.groups().size();
    printf("Number of Groups: %zu\n", sig);
    // for (size_t i = 0; i < sig; i++)
    // {
    //     printf("Point %zu:\n", i);
    //     SunspecGroupPointDef group_i = group.groups().get(i);
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
        SunspecPointDef point = group.points().get(i).value();
        // printf("  ID: %s\n", point.id().value());
        printf("  ID: %s\n", point.id().value().c_str());
        printf("  SF ID: %s\n", point.sf_id().value().c_str());
        printf("  Units: %s\n", point.units().value().c_str());
        printf("  Label: %s\n", point.label().value().c_str());
        printf("  Data Type: %d\n", point.data().type());
        printf("  Data Type: %s\n", SunspecPointData_enum_to_string(point.data().type()));
        printf("  Count: %d\n", point.count());
        printf("  Size: %d\n", point.size());
        printf("  SF: %d\n", point.sf());
        printf("  Access: %hhu\n", point.access());
        printf("  Access: %s\n", SunspecPointAccessType_to_string(point.access()));
        printf("  Mandatory: %hhu\n", point.mandatory());
        printf("  Mandatory: %s\n", SunspecPointMandatoryType_to_string(point.mandatory()));

        switch (point.data().type())
        {
        case SunspecPointData_enum_uint16:
        case SunspecPointData_enum_int16:
            printf("\t\tdata is: %d\n", point.data().data_as_uint16());
            break;
        case SunspecPointData_enum_uint32:
        case SunspecPointData_enum_int32:
            printf("\t\tdata is: %d\n", point.data().data_as_uint32());
            break;
        case SunspecPointData_enum_uint64:
        case SunspecPointData_enum_int64:
            printf("\t\tdata is: %d\n", point.data().data_as_uint64());
            break;
        case SunspecPointData_enum_float32:
        case SunspecPointData_enum_float64:
            printf("\t\tdata is: %lf\n", point.data().data_as_uint16());
            break;
        case SunspecPointData_enum_string:
            printf("\t\tdata is: %s\n", point.data().data_as_string().value().c_str());
            break;
            break;

        default:
            break;
        }
    }

    return 0;
}