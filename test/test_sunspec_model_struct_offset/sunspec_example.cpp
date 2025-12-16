#include "sunspec_model_generated_struct_offset.h"
#include <stdio.h>

int main()
{

    const char *file_name = "model_1_struct_offset.bin";
    FILE *file = fopen(file_name, "rb");

    fseek(file, 0, SEEK_END);     // Move file pointer to the end
    long file_size = ftell(file); // Get current position (which is the file size)
    fclose(file);
    file = fopen(file_name, "rb");
    uint8_t buffer[file_size];
    int a = fread(buffer, 1, file_size, file);
    if (file_size != a)
    {
        fclose(file);

        return -1;
    }

    SunspecModelDefRoot model_root{buffer};
    printf("id: %d\n", model_root.id());
    fclose(file);
}