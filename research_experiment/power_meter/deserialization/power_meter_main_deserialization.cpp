#include <stdio.h>
#include <chrono>

void test_function(const uint8_t *buffer, size_t size);
void test_assert(const uint8_t *buffer, size_t size);

int main(int argc, char **agrv)
{

    if (argc < 2)
    {
        printf("Usage: %s <nakedbytes binary file>\n", agrv[0]);
        return -1;
    }
    const char *file_name = agrv[1];

    FILE *file = fopen(file_name, "rb");
    if (!file)
    {
        printf("Failed to open file: %s\n", file_name);
        return -1;
    }

    fseek(file, 0, SEEK_END);     // Move file pointer to the end
    long file_size = ftell(file); // Get current position (which is the file size)
    fclose(file);
    file = fopen(file_name, "rb");
    uint8_t buffer[file_size];
    int read_len = fread(buffer, 1, file_size, file);
    if (file_size != file_size)
    {
        fclose(file);

        return -1;
    }
    fclose(file);

    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::microseconds;
    using std::chrono::milliseconds;
    using clock = std::chrono::steady_clock;

    auto t1 = clock::now();
    const long int iterations = 100000;
    // Get the root object from the buffer
    for (int i = 0; i < iterations; i++)
    {

        test_function(buffer, file_size);
    }

    auto t2 = clock::now();

    /* Getting number of microseconds as an integer. */
    auto us_int = duration_cast<microseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::micro> us_double = t2 - t1;

    test_assert(buffer, file_size);

    printf("{\"iteration\" : %ld, \"time_taken\" : %ld, \"buffer_size\" : %ld}\n", iterations, us_int.count(), file_size);
    return 0;
}