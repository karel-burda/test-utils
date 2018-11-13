#pragma once

#include <chrono>

#include <gtest/gtest.h>

namespace burda
{
namespace test_utils
{
inline void assert_that_elapsed_time_in_tolerance(std::chrono::duration<double> elapsed,
                                                  std::chrono::duration<double> lower_bound,
                                                  std::chrono::duration<double> upper_bound)
{
    ASSERT_GE(elapsed, lower_bound);
    ASSERT_LE(elapsed, upper_bound);
}
}
}
