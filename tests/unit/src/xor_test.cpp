#include <test_utils/xor.hpp>

namespace
{
TEST(xor, expect)
{
    BURDA_TEST_UTILS_EXPECT_XOR(true, false);
    BURDA_TEST_UTILS_EXPECT_XOR(false, true);

    BURDA_TEST_UTILS_EXPECT_XOR(34, -3999);
}

TEST(xor, assert)
{
    BURDA_TEST_UTILS_ASSERT_XOR(true, false);
    BURDA_TEST_UTILS_ASSERT_XOR(false, true);

    BURDA_TEST_UTILS_ASSERT_XOR(34, -3999);
}
}
