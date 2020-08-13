#include <gtest/gtest.h>

#include <vector>


static void my_copy(
    std::vector<int>::const_iterator begin,
    std::vector<int>::const_iterator end,
    std::vector<int>::iterator destination)
{
    while (begin != end) {
        *destination = *begin;
        ++begin;
        ++destination;
    }
}

static void my_copy(
    std::vector<int>::const_iterator begin,
    std::vector<int>::const_iterator end,
    int* destination)
{
    while (begin != end) {
        *destination = *begin;
        ++begin;
        ++destination;
    }
}

TEST(Vector, NaiveCopy)
{
    std::vector<int> array{0,1,2,3,4,5,6,7,8,9};
    auto begin = array.cbegin();
    auto end = array.cend();

    int another_array[10];
    my_copy(begin, end, another_array);
    ASSERT_EQ(another_array[0], array[0]);
    ASSERT_EQ(another_array[9], array[9]);

    std::vector<int> yet_another_array(3);
    my_copy(begin, begin+3, yet_another_array.begin());
    ASSERT_EQ(yet_another_array[0], array[0]);
    ASSERT_EQ(yet_another_array[2], array[2]);
}
