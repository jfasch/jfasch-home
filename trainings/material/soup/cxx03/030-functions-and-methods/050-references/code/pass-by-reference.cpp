#include <gtest/gtest.h>

void pass_by_reference(int& j)
{
    j = 666;                 // <--- dereference j implicitly
}

TEST(references_suite, reference)
{
    int i = 42;
    pass_by_reference(i);    // <--- take address of i implicitly
    ASSERT_EQ(i, 666);
}
