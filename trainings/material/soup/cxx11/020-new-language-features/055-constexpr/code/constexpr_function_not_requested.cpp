#include <gtest/gtest.h>

constexpr int multiply(int a, int b)
{
    return a*b;
}

// constexpr functions can be used when constexpr not requested
TEST(constexpr_suite, constexpr_function_not_requested)
{
    int a = 10, b = 20;
    int result = multiply(a, b);
    ASSERT_EQ(result, 200);
}
