#include <gtest/gtest.h>

#include <vector>
#include <algorithm>


TEST(Vector, AlgoCopy)
{
    std::vector<int> array{0,1,2,3,4,5,6,7,8,9};

    int another_array[10];
    std::copy(array.cbegin(), array.cend(), another_array);
    ASSERT_EQ(another_array[0], array[0]);
    ASSERT_EQ(another_array[9], array[9]);

    int yet_another_array[3];
    std::copy(array.cbegin(), array.cbegin()+3, yet_another_array);
    ASSERT_EQ(yet_another_array[0], array[0]);
    ASSERT_EQ(yet_another_array[2], array[2]);
}

TEST(Vector, BackInsert)
{
    std::vector<int> array{0,1,2,3,4,5,6,7,8,9};
    std::vector<int> another_array; // empty
    // std::copy(array.cbegin(), array.cbegin()+3, another_array); // bug
    std::copy(array.cbegin(), array.cend(),
              std::back_insert_iterator<std::vector<int>>(another_array));
    ASSERT_EQ(another_array[0], array[0]);
    ASSERT_EQ(another_array[9], array[9]);
}
