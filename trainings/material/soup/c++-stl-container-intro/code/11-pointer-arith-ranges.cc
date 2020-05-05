#include <gtest/gtest.h>


static void copy(const int* begin, const int* end, int* destination)
{
    while (begin != end) {
        *destination = *begin;
        ++begin;
        ++destination;
    }
}

TEST(PointerArithmetics, Ranges)
{
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    size_t num_elements = sizeof(array)/sizeof(int);

    const int* begin = array;
    const int* end = array + num_elements;

    int another_array[10];
    copy(begin, end, another_array);
    ASSERT_EQ(another_array[0], array[0]);
    ASSERT_EQ(another_array[9], array[9]);

    int yet_another_array[3];
    copy(begin, begin+3, yet_another_array);
    ASSERT_EQ(yet_another_array[0], array[0]);
    ASSERT_EQ(yet_another_array[2], array[2]);
}
