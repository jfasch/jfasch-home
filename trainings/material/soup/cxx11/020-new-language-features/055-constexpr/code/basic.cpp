#include <gtest/gtest.h>

TEST(constexpr_suite, basic)
{
    constexpr int a = 10;
    constexpr int i = a*2;
    ASSERT_EQ(i, 20);
}
