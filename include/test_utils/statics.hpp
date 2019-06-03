#pragma once

#include <type_traits>

namespace burda
{
namespace test_utils
{
namespace statics
{
template <typename class_type, const bool constructible>
constexpr void assert_default_constructibility()
{
    static_assert(std::is_default_constructible<class_type>::value == constructible,
                  "Given class_type has incorrect constructibility");
}

template <typename class_type, const bool constructible>
constexpr void assert_move_constructibility()
{
    static_assert(std::is_move_constructible<class_type>::value == constructible,
                  "Given class_type has incorrect move constructibility");
    static_assert(std::is_move_assignable<class_type>::value == constructible,
                  "Given class_type has incorrect move assignability");
}

template <typename class_type, const bool constructible>
constexpr void assert_copy_constructibility()
{
    static_assert(std::is_copy_constructible<class_type>::value == constructible,
                  "Given class_type has incorrect copy constructibility");
    static_assert(std::is_copy_assignable<class_type>::value == constructible,
                  "Given class_type has incorrect copy assignability");
}
}
}
}
