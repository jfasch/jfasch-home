#include <gtest/gtest.h>

int multiply(int a, int b)
{
    return a*b;
}

TEST(constexpr_suite, non_constexpr_function)
{
    constexpr int result = multiply(10, 20);
    ASSERT_EQ(result, 200);
}
