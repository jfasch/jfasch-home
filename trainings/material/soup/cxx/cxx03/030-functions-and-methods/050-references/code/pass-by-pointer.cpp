#include <gtest/gtest.h>

void pass_by_pointer(int* j)
{
    *j = 666;              // <--- dereference j explicitly 
}

TEST(references_suite, pointer)
{
    int i = 42;
    pass_by_pointer(&i);   // <--- take address of i explicitly
    ASSERT_EQ(i, 666);
}
