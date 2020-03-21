#include <gtest/gtest.h>
#include <iostream>

TEST(AssertDemo, AssertIsFatal)
{
    ASSERT_TRUE('X' == 'U');
    ASSERT_EQ('X', 'U');
    std::cout << "succeeded" << std::endl;
}
