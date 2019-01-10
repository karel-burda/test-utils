#include <test_utils/xor.hpp>

namespace
{
TEST(xor, expect)
{
    BURDA_TEST_UTILS_XOR_EXPECT(true, false);
    BURDA_TEST_UTILS_XOR_EXPECT(false, true);

    BURDA_TEST_UTILS_XOR_EXPECT(34, -3999);
}

TEST(xor, assert)
{
    BURDA_TEST_UTILS_XOR_ASSERT(true, false);
    BURDA_TEST_UTILS_XOR_ASSERT(false, true);

    BURDA_TEST_UTILS_XOR_ASSERT(34, -3999);
}
}
