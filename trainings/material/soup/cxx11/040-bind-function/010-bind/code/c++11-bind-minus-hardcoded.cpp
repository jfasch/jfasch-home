#include <gtest/gtest.h>
#include <functional>

static int minus(int i, int j)
{
    return i-j;
}

TEST(bind_suite, minus_hardcoded)
{
    auto _1_minus_2 = std::bind(minus, 1, 2);
    ASSERT_EQ(_1_minus_2(), -1);
}
