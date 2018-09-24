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
                                           std::chrono::duration<double> upper_bound,
                                           std::chrono::duration<double> epsilon = std::chrono::milliseconds{ 10 })
{
    ASSERT_GE(elapsed + epsilon, lower_bound);
    ASSERT_LE(elapsed, upper_bound);
}

inline std::chrono::duration<double> measure_time(std::function<void()> action)
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
