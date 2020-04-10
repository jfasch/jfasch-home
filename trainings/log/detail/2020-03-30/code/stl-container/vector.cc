#include <gtest/gtest.h>

#include <algorithm>


TEST(Vector, Initialization)
{
    std::vector<int> array;
    array.push_back(42);
    array.push_back(7);
    array.push_back(666);

    ASSERT_EQ(array[0], 42);
    ASSERT_EQ(array[1], 7);
    ASSERT_EQ(array[2], 666);
}

TEST(Vector, Initialization_CXX11)
{
    const std::vector<int> array{42, 7, 666};

    ASSERT_EQ(array[0], 42);
    ASSERT_EQ(array[1], 7);
    ASSERT_EQ(array[2], 666);
}

TEST(Vector, Copy_OldSchool)
{
    const std::vector<int> array{42, 7, 666};
    int dest[3];

    // copy "algorithm"
    // auto source_begin = array.cbegin();
    // auto source_end = array.cend();
    const int* source_begin = &array[0];
    const int* source_end = &array[3];
    int* dest_begin = dest;

    while (source_begin != source_end)
        *dest_begin++ = *source_begin++;

    ASSERT_EQ(dest[0], 42);
    ASSERT_EQ(dest[1], 7);
    ASSERT_EQ(dest[2], 666);
}

TEST(Vector, Copy_Algorithm)
{
    std::vector<int> array{42, 7, 666};
    int dest[3];

    std::copy(array.cbegin(), array.cend(), dest);

    ASSERT_EQ(dest[0], 42);
    ASSERT_EQ(dest[1], 7);
    ASSERT_EQ(dest[2], 666);
}

TEST(Vector, Sort_Algorithm)
{
    std::vector<int> array{42, 7, 666, 10};

    std::sort(array.begin(), array.end());

    ASSERT_EQ(array[0], 7);
    ASSERT_EQ(array[1], 10);
    ASSERT_EQ(array[2], 42);
    ASSERT_EQ(array[3], 666);
}

TEST(Vector, Sort_Algorithm_2)
{
    std::vector<int> array{42, 7, 666, 10};

    std::sort(array.begin()+1, array.end());

    ASSERT_EQ(array[0], 42);
    ASSERT_EQ(array[1], 7);
    ASSERT_EQ(array[2], 10);
    ASSERT_EQ(array[3], 666);
}


static bool less_int(int l, int r)
{
    return l<r;
}
TEST(Vector, Sort_Algorithm_ExplicitIntLessThanCompare)
{
    std::vector<int> array{42, 7, 666, 10};

    std::sort(array.begin(), array.end(), less_int);

    ASSERT_EQ(array[0], 7);
    ASSERT_EQ(array[1], 10);
    ASSERT_EQ(array[2], 42);
    ASSERT_EQ(array[3], 666);
}

static bool greater_int(int l, int r)
{
    return l>r;
}
TEST(Vector, Sort_Algorithm_Reverse)
{
    std::vector<int> array{42, 7, 666, 10};

    std::sort(array.begin(), array.end(), greater_int);

    ASSERT_EQ(array[0], 666);
    ASSERT_EQ(array[1], 42);
    ASSERT_EQ(array[2], 10);
    ASSERT_EQ(array[3], 7);
}

TEST(Vector, Sort_Algorithm_Reverse_Lambda)
{
    std::vector<int> array{42, 7, 666, 10};

    std::sort(array.begin(), array.end(), [](int l, int r){return l>r;});

    ASSERT_EQ(array[0], 666);
    ASSERT_EQ(array[1], 42);
    ASSERT_EQ(array[2], 10);
    ASSERT_EQ(array[3], 7);
}

