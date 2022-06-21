#include <gtest/gtest.h>

void pass_by_const_reference(const int& j)
{
    j = 666;                 // <--- error: j is const
}

TEST(references_suite, const_reference)
{
    int i = 42;
    pass_by_const_reference(i);    // <--- pass reference to const i
    ASSERT_EQ(i, 666);
}
