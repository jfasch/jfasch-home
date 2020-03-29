#include <gtest/gtest.h>

#include <vector>


TEST(Vector, Basics_CXX03)
{
    std::vector<int> array;
    for (int i=0; i<10; i++)
        array.push_back(i);

    // int* ip = &array[0]; // works
    // int* ip = array.begin(); // error
    // std::vector<int>::iterator ip = array.begin();
    std::vector<int>::const_iterator ip = array.begin();

    ASSERT_EQ(*ip, 0);
    ASSERT_EQ(ip[0], 0);

    ASSERT_EQ(*(ip+9), 9);
    ASSERT_EQ(ip[9], 9);
}

TEST(Vector, Basics_CXX11)
{
    std::vector<int> array{0,1,2,3,4,5,6,7,8,9};
    auto ip = array.cbegin();

    ASSERT_EQ(*ip, 0);
    ASSERT_EQ(ip[0], 0);

    ASSERT_EQ(*(ip+9), 9);
    ASSERT_EQ(ip[9], 9);
}
