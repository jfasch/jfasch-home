#include <gtest/gtest.h>

TEST(OneSuite, Test1) {}
TEST(OneSuite, Test2) {}
TEST(AnotherSuite, Test1) {}
TEST(AnotherSuite, Test2) {}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
