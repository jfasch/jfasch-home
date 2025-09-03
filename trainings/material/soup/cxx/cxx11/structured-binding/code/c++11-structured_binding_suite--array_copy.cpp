#include <gtest/gtest.h>

TEST(structured_binding_suite, array_copy)
{
    int array[] {1, 2, 3};

    auto [x, y, z] = array;

    ASSERT_EQ(x, array[0]);
    ASSERT_EQ(y, array[1]);
    ASSERT_EQ(z, array[2]);

    // x, y, z are *copies*, so assignment does not go through to the
    // originals
    x = y = z = 666;
    ASSERT_NE(array[0], 666);
    ASSERT_NE(array[1], 666);
    ASSERT_NE(array[2], 666);
}
