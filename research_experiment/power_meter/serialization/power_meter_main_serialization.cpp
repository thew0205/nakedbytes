#include <stdio.h>
#include <chrono>

void test_function();
size_t test_assert();

int main(int argc, char **agrv)
{
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

        test_function();
    }

    auto t2 = clock::now();

    /* Getting number of microseconds as an integer. */
    auto us_int = duration_cast<microseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::micro> us_double = t2 - t1;

    

    size_t size = test_assert();

    printf("{\"iteration\" : %ld, \"time_taken\" : %ld, \"buffer_size\" : %ld}\n", iterations, us_int.count(), size);
    return 0;
}