#include <string>

#include <gtest/gtest.h>

#include <test_utils/test_utils.hpp>

namespace
{
namespace test_utils = burda::test_utils;

TEST(test_utils, assert_construction_and_destruction)
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

TEST(test_utils, check_if_mutex_is_owned)
{
    std::mutex lock;

    EXPECT_NO_THROW(test_utils::check_if_mutex_is_owned(lock, false));

    lock.lock();

    EXPECT_NO_THROW(test_utils::check_if_mutex_is_owned(lock, true));
}
}
