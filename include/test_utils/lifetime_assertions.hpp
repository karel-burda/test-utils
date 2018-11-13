#pragma once

#include <gtest/gtest.h>

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
