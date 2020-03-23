#include <gtest/gtest.h>


class TheFixture : public ::testing::Test
{
protected:
    int initial_state = 666; // C++11!
};

TEST_F(TheFixture, TestThatModifiesState)
{
    initial_state = 42;
}

TEST_F(TheFixture, ParanoidTest)
{
    // don't trust anybody!
    ASSERT_EQ(initial_state, 666);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
