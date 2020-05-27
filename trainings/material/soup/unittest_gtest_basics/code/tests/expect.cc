#include <gtest/gtest.h>

TEST(ExpectDemo, ExpectIsNonFatal)
{
    EXPECT_TRUE('X' == 'U');
    EXPECT_EQ('X', 'U');
}
