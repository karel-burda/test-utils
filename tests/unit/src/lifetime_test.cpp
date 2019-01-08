#include <string>

#include <test_utils/lifetime.hpp>

namespace
{
namespace test_utils = burda::test_utils;

TEST(lifetime, assert_construction_and_destruction)
{
    EXPECT_NO_THROW(test_utils::assert_construction_and_destruction<int>());
    EXPECT_NO_THROW(test_utils::assert_construction_and_destruction<float>(999.0f));

    struct Foo
    {
        Foo() = default;

        Foo(std::string, float)
        {
        }
    };

    EXPECT_NO_THROW(test_utils::assert_construction_and_destruction<Foo>());
    EXPECT_NO_THROW(test_utils::assert_construction_and_destruction<Foo>("bar", 1.0f));
}
}
