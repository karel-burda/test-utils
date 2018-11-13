#include <test_utils/macros.hpp>

namespace
{
TEST(macros, xor_expect)
{
    BURDA_TEST_UTILS_EXPECT_XOR(true, false);
    BURDA_TEST_UTILS_EXPECT_XOR(false, true);

    BURDA_TEST_UTILS_EXPECT_XOR(34, -3999);
}

TEST(macros, xor_assert)
{
    BURDA_TEST_UTILS_ASSERT_XOR(true, false);
    BURDA_TEST_UTILS_ASSERT_XOR(false, true);

    BURDA_TEST_UTILS_ASSERT_XOR(34, -3999);
}
}
