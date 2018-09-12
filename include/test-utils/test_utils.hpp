#pragma once

#include <mutex>

#include <gtest/gtest.h>

#define EXPECT_XOR(condition1, condition2) EXPECT_NE(!condition1, !condition2);

namespace burda
{
namespace test_utils
{
template <typename class_type>
void assert_construction_and_destruction(const bool call_destructor = true)
{
    ASSERT_NO_THROW(class_type instance);

    class_type instance;
    if (call_destructor)
    {
        EXPECT_NO_THROW(instance.~class_type());
    }
}

void check_if_mutex_is_owned(std::mutex & mutex, bool should_be_owned)
{
    const auto is_mutex_owned = !mutex.try_lock();
    EXPECT_EQ(is_mutex_owned, should_be_owned);

    if (!is_mutex_owned)
    {
        mutex.unlock();
    }
}
}
}
