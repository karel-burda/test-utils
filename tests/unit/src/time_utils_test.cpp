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

TEST(time_utils, measure_duration)
{
    EXPECT_THROW(test_utils::measure_duration(nullptr), std::runtime_error);

    {
        const auto duration = test_utils::measure_duration([]() {});
        EXPECT_TRUE(duration <= 1s);
    }

    {
        const auto duration = test_utils::measure_duration([]() { std::this_thread::sleep_for(4s); });
        EXPECT_TRUE(duration >= 4s && duration <= 8s);
    }
}
}
