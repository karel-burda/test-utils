#pragma once

#include <gtest/gtest.h>

namespace burda
{
namespace test_utils
{
namespace lifetime
{
template <typename class_type, typename... arguments>
void assert_construction_and_destruction(arguments... args)
{
    ASSERT_NO_THROW(class_type instance{ std::forward<arguments>(args)... }; (void)instance);
}
}
}
}
