#include <gtest/gtest.h>

#include <test_utils/static_class_assertions.hpp>

namespace
{
namespace test_utils = burda::test_utils;

TEST(static_class_assertions, assertions)
{
    struct struct_with_rule_of_five_enabled
    {
        struct_with_rule_of_five_enabled() = default;
        ~struct_with_rule_of_five_enabled() = default;

        struct_with_rule_of_five_enabled(const struct_with_rule_of_five_enabled &) = default;
        struct_with_rule_of_five_enabled & operator=(const struct_with_rule_of_five_enabled &) = default;

        struct_with_rule_of_five_enabled & operator=(struct_with_rule_of_five_enabled &&) = default;
        struct_with_rule_of_five_enabled(struct_with_rule_of_five_enabled &&) = default;
    };

    test_utils::assert_default_constructibility<struct_with_rule_of_five_enabled, true>();
    test_utils::assert_copy_constructibility<struct_with_rule_of_five_enabled, true>();
    test_utils::assert_move_constructibility<struct_with_rule_of_five_enabled, true>();
}
}
