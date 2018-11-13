#pragma once

#include <gtest/gtest.h>

#define EXPECT_XOR(condition1, condition2) EXPECT_NE(!condition1, !condition2);

namespace burda
{
namespace test_utils
{
template <typename class_type, typename... args>
void assert_construction_and_destruction(args... a)
{
    ASSERT_NO_THROW(class_type instance{ std::forward<args>(a)... }; (void)instance);

    class_type instance{ std::forward<args>(a)... };

    // explicit unused variable compiler suppression
    (void)instance;
}
}
}
