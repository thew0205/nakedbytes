#include "sunspec_model_generated_struct_offset.h"
#include "model_struct_offset_1.h"
int main()
{
    SunspecModelDef model = {modelDefinition};

    printf("Model ID: %d\n", model.id());
    SunspecGroupPointDef group = model.group().value();
    printf("Group ID: %s\n", group.id().value());
    printf("Group Count Point ID: %s\n", group.count_point_id().value());
    printf("Group Label: %s\n", group.label().value());
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
        printf("  ID: %s\n", point.id().value());
        printf("  SF ID: %s\n", point.sf_id().value());
        printf("  Units: %s\n", point.units().value());
        printf("  Label: %s\n", point.label().value());
        printf("  Data Type: %d\n", point.data().type());
        printf("  Count: %d\n", point.count());
        printf("  Size: %d\n", point.size());
        printf("  SF: %d\n", point.sf());
        // printf("  Access: %d\n", point.access());
        // printf("  Mandatory: %d\n", point.mandatory());
        if (point.data().type() == 0)
        {
            printf("  \t\t\tdata is: %d\n", *(uint16_t *)point.data().raw_data());
        }
    }

    
    return 0;
}