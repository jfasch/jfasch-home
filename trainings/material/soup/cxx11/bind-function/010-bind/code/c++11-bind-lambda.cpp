#include <functional>
#include <gtest/gtest.h>

TEST(bind_suite, lambda)
{
    auto func = [val=42](int i){ return val+i; };
    auto funcfunc = std::bind(func, 1);
    ASSERT_EQ(funcfunc(), 43);
}
