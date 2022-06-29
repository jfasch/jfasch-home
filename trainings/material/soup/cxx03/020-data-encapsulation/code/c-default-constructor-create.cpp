#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

struct point point_create_default(void)   // <--- "constructor" in C
{
    struct point p;
    p.x = 0;
    p.y = 0;
    return p;
}

TEST(point_c_suite, c_default_constructor_create)
{
    struct point p = point_create_default();   // <--- uninitialized state not possible

    ASSERT_EQ(p.x, 0);
    ASSERT_EQ(p.y, 0);
}
