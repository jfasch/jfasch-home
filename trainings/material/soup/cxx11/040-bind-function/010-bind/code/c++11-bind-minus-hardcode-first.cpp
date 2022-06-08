#include <gtest/gtest.h>
#include <functional>

static int minus(int i, int j)
{
    return i-j;
}

TEST(bind_suite, minus_hardcode_first_parameter)
{
    auto _42_minus_param = std::bind(minus, 42, std::placeholders::_1);
    ASSERT_EQ(_42_minus_param(1), 41);
}
