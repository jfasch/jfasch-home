#include <gtest/gtest.h>

TEST(operators_suite, int_plus_equal)
{
    int i = 1;

    int j = i += 1;   // <--- operator+=() has a value!

    ASSERT_EQ(i, 2);
    ASSERT_EQ(j, i);
}
