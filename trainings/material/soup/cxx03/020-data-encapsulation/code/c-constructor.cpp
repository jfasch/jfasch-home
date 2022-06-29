#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

struct point point_create(int x, int y)
{
    struct point p = {x,y};
    return p;
}

TEST(point_c_suite, c_constructor)
{
    struct point p = point_create(1,2);
    
    ASSERT_EQ(p.x, 1);
    ASSERT_EQ(p.y, 2);
}
