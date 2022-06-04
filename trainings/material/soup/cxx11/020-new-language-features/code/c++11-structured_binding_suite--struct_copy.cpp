#include <gtest/gtest.h>

struct point
{
    int x, y;
};

TEST(structured_binding_suite, struct_copy)
{
    point p{1,2};

    auto [x, y] = p;

    ASSERT_EQ(x, p.x);
    ASSERT_EQ(y, p.y);

    // copy
    x = y = 666;
    ASSERT_NE(p.x, 666);
    ASSERT_NE(p.y, 666);
}
