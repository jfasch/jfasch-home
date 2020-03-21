#include <gtest/gtest.h>
#include <iostream>

TEST(FailDemo, FailIsFatal)
{
    FAIL();
    std::cout << "succeeded" << std::endl;
}
