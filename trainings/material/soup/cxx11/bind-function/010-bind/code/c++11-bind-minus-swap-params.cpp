#include <gtest/gtest.h>
#include <functional>

static int minus(int i, int j)
{
    return i-j;
}

TEST(bind_suite, minus_swap_parameters)
{
    auto second_minus_first = std::bind(minus, std::placeholders::_2, std::placeholders::_1);
    ASSERT_EQ(second_minus_first(1, 2), 1);
}

