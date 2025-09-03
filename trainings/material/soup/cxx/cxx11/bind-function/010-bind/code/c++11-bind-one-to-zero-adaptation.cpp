#include <gtest/gtest.h>
#include <functional>

static int one_parameter_function(int i)
{
    return i*2;
}

TEST(bind_suite, plain_one_parameter_function)
{
    auto func = std::bind(one_parameter_function, 1);
    ASSERT_EQ(func(), 2);
}
