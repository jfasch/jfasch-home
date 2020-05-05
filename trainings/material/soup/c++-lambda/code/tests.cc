#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include <algorithm>


TEST(Lambda, IntVectorSortDefault)
{
    std::vector<int> array{2,1,666,42};
    std::sort(array.begin(), array.end());

    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 2);
    ASSERT_EQ(array[2], 42);
    ASSERT_EQ(array[3], 666);
}

static bool greater(int l, int r)
{
    return l > r;
}
TEST(Lambda, IntVectorSortReverseClumsy)
{
    std::vector<int> array{2,1,666,42};
    std::sort(array.begin(), array.end(), greater);

    ASSERT_EQ(array[0], 666);
    ASSERT_EQ(array[1], 42);
    ASSERT_EQ(array[2], 2);
    ASSERT_EQ(array[3], 1);
}

TEST(Lambda, IntVectorSortReverseLambda)
{
    std::vector<int> array{2,1,666,42};
    std::sort(array.begin(), array.end(), [](int l, int r) { return l>r; });

    ASSERT_EQ(array[0], 666);
    ASSERT_EQ(array[1], 42);
    ASSERT_EQ(array[2], 2);
    ASSERT_EQ(array[3], 1);
}

class Less_CountingCalls
{
public:
    Less_CountingCalls(unsigned& n) : _n(n) {}
    bool operator()(int l, int r) { _n++; return l<r; }
private:
    unsigned& _n;
};
TEST(Lambda, IntVectorSort_Count_Comparisons_Clumsy)
{
    std::vector<int> array{2,1,666,42};

    unsigned n_calls = 0;
    std::sort(array.begin(), array.end(), Less_CountingCalls(n_calls));
    ASSERT_NE(n_calls, 0);

    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 2);
    ASSERT_EQ(array[2], 42);
    ASSERT_EQ(array[3], 666);
}

TEST(Lambda, IntVectorSort_Count_Comparisons_Lambda)
{
    std::vector<int> array{2,1,666,42};

    unsigned n_calls = 0;
    std::sort(array.begin(), array.end(), [&n_calls](unsigned l, unsigned r){ n_calls++; return l<r; });
    ASSERT_NE(n_calls, 0);

    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 2);
    ASSERT_EQ(array[2], 42);
    ASSERT_EQ(array[3], 666);
}
