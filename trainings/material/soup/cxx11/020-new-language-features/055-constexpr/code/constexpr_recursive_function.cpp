#include <gtest/gtest.h>

constexpr int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

// constexpr request can be recursive
TEST(constexpr_suite, constexpr_recursive_function)
{
    constexpr int f = fibonacci(20);
    ASSERT_EQ(f, 6765);
}
