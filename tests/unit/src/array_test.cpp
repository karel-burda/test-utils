#include <limits>

#include <test_utils/array.hpp>

namespace
{
TEST(array, expect)
{
    const int array1[] = { 1, 2, 3 };
    const int array2[] = { 1, 2, 3 };

    BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(array1, array2, 3);
}

TEST(array, assert)
{
    const unsigned long long array1[] = { std::numeric_limits<unsigned long long>::min(), std::numeric_limits<unsigned long long>::max() };
    const unsigned long long array2[] = { std::numeric_limits<unsigned long long>::min(), std::numeric_limits<unsigned long long>::max() };

    BURDA_TEST_UTILS_ARRAY_ASSERT_EQUAL(array1, array2, 2);
}
}
