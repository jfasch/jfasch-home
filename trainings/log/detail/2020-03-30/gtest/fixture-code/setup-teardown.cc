#include <gtest/gtest.h>


// attention: this is complete nonsense. it only demonstrates SetUp()
// (and TearDown(), for that matter)
class ComplexFixture : public ::testing::Test
{
protected:
    static const int N = 28;
    std::vector<int> first_n;

private: // :-)
    void SetUp() override
    {
        for (int i=0; i<N; i++)
            first_n.push_back(i);
    }
};

TEST_F(ComplexFixture, SomeTest)
{
    ASSERT_EQ(first_n[10], 10);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
