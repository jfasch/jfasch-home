#include <gtest/gtest.h>


TEST(PointerArithmetics, Basics)
{
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    int* ip = array; // &array[0]

    ASSERT_EQ(*ip, 0);
    ASSERT_EQ(ip[0], 0);

    ASSERT_EQ(*(ip+9), 9);
    ASSERT_EQ(ip[9], 9);

    int* bugp = ip + 10; // one off

    // ASSERT_EQ(*bugp, 10);
    (void)bugp;
}
