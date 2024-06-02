#include <gtest/gtest.h>
#include <any>

TEST(any_suite, has_value)
{
    std::any a = 42;
    ASSERT_TRUE(a.has_value());

    a.reset();
    ASSERT_FALSE(a.has_value());
}

