#include <gtest/gtest.h>

constexpr int multiply(int a, int b)
{
    return a*b;
}

TEST(constexpr_suite, constexpr_function_requested)
{
    constexpr int result = multiply(10, 20);
    ASSERT_EQ(result, 200);
}
