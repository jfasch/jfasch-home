#include <gtest/gtest.h>

TEST(structured_binding_suite, array_reference)
{
    int array[] {1, 2, 3};

    auto& [x, y, z] = array;

    ASSERT_EQ(x, array[0]);
    ASSERT_EQ(y, array[1]);
    ASSERT_EQ(z, array[2]);

    // x, y, z are *references*, so assignment to those goes though
    // right into the original array members
    x = y = z = 666;
    ASSERT_EQ(array[0], 666);
    ASSERT_EQ(array[1], 666);
    ASSERT_EQ(array[2], 666);
}
