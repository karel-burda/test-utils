#pragma once

#include <mutex>

#include <gtest/gtest.h>

namespace burda
{
namespace test_utils
{
inline void check_if_mutex_is_owned(std::mutex & mutex, bool should_be_owned)
{
    const auto is_mutex_owned = !mutex.try_lock();
    EXPECT_EQ(is_mutex_owned, should_be_owned);

    // if the mutex was previously not owned, we have to unlock it now (because we've performed to lock it)
    if (!is_mutex_owned)
    {
         mutex.unlock();
    }
}
}
}
