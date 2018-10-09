#include <thread>

#include <gtest/gtest.h>

#include <test_utils/time_utils.hpp>

namespace
{
using namespace std::chrono_literals;
namespace test_utils = burda::test_utils;

TEST(time_utils, assert_that_elapsed_time_in_tolerance)
{
    EXPECT_NO_THROW(test_utils::assert_that_elapsed_time_in_tolerance(7s, 5s, 9s));
    EXPECT_NO_THROW(test_utils::assert_that_elapsed_time_in_tolerance(100ms, 100ms, 100ms));
}
}
