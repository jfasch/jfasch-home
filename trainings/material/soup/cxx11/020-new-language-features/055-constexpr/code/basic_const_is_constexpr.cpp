#include <gtest/gtest.h>

TEST(constexpr_suite, basic_const_is_constexpr)
{
    const int a = 10;
    constexpr int i = a*2;
    ASSERT_EQ(i, 20);
}
