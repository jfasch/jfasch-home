#include <gtest/gtest.h>
#include <functional>

static int void_function()
{
    return 42;
}

TEST(bind_suite, plain_void_function)
{
    auto func = std::bind(void_function);
    ASSERT_EQ(func(), 42);
}
