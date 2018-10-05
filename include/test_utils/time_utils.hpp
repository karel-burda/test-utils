#pragma once

#include <chrono>
#include <functional>
#include <stdexcept>

#include <gtest/gtest.h>

namespace burda
{
namespace test_utils
{
using clock = std::chrono::steady_clock;

inline void assert_that_elapsed_time_in_tolerance(std::chrono::duration<double> elapsed,
                                                  std::chrono::duration<double> lower_bound,
                                                  std::chrono::duration<double> upper_bound)
{
    ASSERT_GE(elapsed, lower_bound);
    ASSERT_LE(elapsed, upper_bound);
}

inline std::chrono::duration<double> measure_duration(std::function<void()> action)
{
    const auto start = clock::now();

    if (action)
    {
        action();
    }
    else
    {
        throw std::runtime_error{ "Given action is not callable" };
    }

    const auto end = clock::now();

    return end - start;
}
}
}
