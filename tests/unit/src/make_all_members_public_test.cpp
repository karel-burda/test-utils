#include <gtest/gtest.h>

namespace
{
TEST(make_all_members_public, static_assertions)
{
#include <test_utils/make_all_members_public.hpp>
    class class_with_protected_and_private
    {
    public:
        bool method_public() const
        {
            return true;
        }

        const bool member_public = false;

    protected:
        bool method_protected() const
        {
            return true;
        }

        const bool member_protected = false;

    private:
        bool method_private() const
        {
            return true;
        }

        const bool member_private = false;
    };

    // make sure all members are accessible
    class_with_protected_and_private instance;
    EXPECT_EQ(instance.method_public(), true);
    EXPECT_EQ(instance.member_public, false);
    EXPECT_EQ(instance.method_protected(), true);
    EXPECT_EQ(instance.member_protected, false);
    EXPECT_EQ(instance.method_private(), true);
    EXPECT_EQ(instance.member_private, false);
}
}
