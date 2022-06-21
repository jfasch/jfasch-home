#include <gtest/gtest.h>

void pass_by_copy(int j)
{
    j = 666;
}

TEST(references_suite, copy)
{
    int i = 42;
    pass_by_copy(i);
    ASSERT_EQ(i, 42);
}
