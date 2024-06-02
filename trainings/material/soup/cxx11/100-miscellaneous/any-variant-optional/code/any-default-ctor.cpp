#include <gtest/gtest.h>
#include <any>

TEST(any_suite, default_ctor)
{
    std::any a;

    ASSERT_EQ(a.type(), typeid(void));
    ASSERT_FALSE(a.has_value());
}
