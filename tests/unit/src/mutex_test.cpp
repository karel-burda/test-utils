#include <string>

#include <test_utils/mutex.hpp>

namespace
{
namespace test_utils = burda::test_utils;

TEST(mutex, check_if_mutex_is_owned)
{
    std::mutex lock;

    test_utils::mutex::check_if_owned(lock, false);

    lock.lock();

    test_utils::mutex::check_if_owned(lock, true);
}
}
