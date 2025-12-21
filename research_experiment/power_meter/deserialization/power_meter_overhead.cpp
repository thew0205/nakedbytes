#include <stdint.h>
#include <cstddef>
#include <assert.h>

void test_function(const uint8_t *buffer, size_t size) {}

void test_assert(const uint8_t *buffer, size_t size)
{
    assert(true);
}