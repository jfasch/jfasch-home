#include <gtest/gtest.h>

void pass_by_const_pointer(const int* j)
{
    *j = 666;              // <--- error: *j is const
}

TEST(references_suite, const_pointer)
{
    int i = 42;
    pass_by_const_pointer(&i);   // <--- pass address to *const* i
}
