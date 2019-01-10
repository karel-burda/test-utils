#include <test_utils/array.hpp>

namespace
{
TEST(array, macros)
{
    int array1 = { 1, 2, 3 };
    int array2 = { 1, 2, 3 };

    BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(array1, array2, 3);
    BURDA_TEST_UTILS_ARRAY_ASSERT_EQUAL(array1, array2, 3);
}
}
