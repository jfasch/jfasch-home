#include <gtest/gtest.h>

TEST(FailDemo, FailIsFatal)
{
    FAIL();
}
TEST(FailDemo, AssertIsFatal)
{
    ASSERT_TRUE('X' == 'U');
}
TEST(FailDemo, ExpectIsNonFatal)
{
    EXPECT_TRUE('X' == 'U');
    EXPECT_TRUE(42 == 666);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
