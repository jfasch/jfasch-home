#include <gtest/gtest.h>
#include <iostream>

TEST(AssertDemo, AssertIsFatal)
{
    ASSERT_TRUE('X' == 'U');
    std::cout << "succeeded" << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
