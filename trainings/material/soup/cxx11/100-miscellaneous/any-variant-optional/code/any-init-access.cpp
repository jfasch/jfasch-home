#include <gtest/gtest.h>
#include <any>

TEST(any_suite, basic)
{
    std::any a = 42;                                   // <--- int
    ASSERT_EQ(a.type(), typeid(int));
    int i = std::any_cast<int>(a);
    ASSERT_EQ(i, 42);

    a = 37.6;                                          // <--- double
    ASSERT_EQ(a.type(), typeid(double));
    double d = std::any_cast<double>(a);
    ASSERT_FLOAT_EQ(d, 37.6);
}
