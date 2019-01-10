#include <gtest/gtest.h>

#include <test_utils/statics.hpp>

namespace
{
namespace test_utils = burda::test_utils;

TEST(statics, constructibility_enabled)
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

    test_utils::statics::assert_default_constructibility<struct_with_rule_of_five_enabled, true>();
    test_utils::statics::assert_copy_constructibility<struct_with_rule_of_five_enabled, true>();
    test_utils::statics::assert_move_constructibility<struct_with_rule_of_five_enabled, true>();
}

TEST(statics, constructibility_disabled)
{
    struct struct_with_rule_of_five_disabled
    {
        struct_with_rule_of_five_disabled() = delete;
        ~struct_with_rule_of_five_disabled() = default;

        struct_with_rule_of_five_disabled(const struct_with_rule_of_five_disabled &) = delete;
        struct_with_rule_of_five_disabled & operator=(const struct_with_rule_of_five_disabled &) = delete;

        struct_with_rule_of_five_disabled & operator=(struct_with_rule_of_five_disabled &&) = delete;
        struct_with_rule_of_five_disabled(struct_with_rule_of_five_disabled &&) = delete;
    };

    test_utils::statics::assert_default_constructibility<struct_with_rule_of_five_disabled, false>();
    test_utils::statics::assert_copy_constructibility<struct_with_rule_of_five_disabled, false>();
    test_utils::statics::assert_move_constructibility<struct_with_rule_of_five_disabled, false>();
}

TEST(statics, constructibility_mixed)
{
    struct struct_with_rule_of_five_mixed
    {
        struct_with_rule_of_five_mixed() = default;
        ~struct_with_rule_of_five_mixed() = default;

        struct_with_rule_of_five_mixed(const struct_with_rule_of_five_mixed &) = default;
        struct_with_rule_of_five_mixed & operator=(const struct_with_rule_of_five_mixed &) = default;

        struct_with_rule_of_five_mixed & operator=(struct_with_rule_of_five_mixed &&) = delete;
        struct_with_rule_of_five_mixed(struct_with_rule_of_five_mixed &&) = delete;
    };

    test_utils::statics::assert_default_constructibility<struct_with_rule_of_five_mixed, true>();
    test_utils::statics::assert_copy_constructibility<struct_with_rule_of_five_mixed, true>();
    test_utils::statics::assert_move_constructibility<struct_with_rule_of_five_mixed, false>();
}
}
