#include <gtest/gtest.h>

TEST(ExpectDemo, ExpectIsNonFatal)
{
    EXPECT_TRUE('X' == 'U');
    EXPECT_EQ('X', 'U');
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
