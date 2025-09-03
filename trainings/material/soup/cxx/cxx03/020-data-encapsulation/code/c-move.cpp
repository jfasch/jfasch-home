#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

void point_move(point* self, int x, int y)
{
    self->x += x;
    self->y += y;
}

TEST(point_c_suite, move)
{
    point p = {1,2};

    point_move(&p, 3, 4);

    ASSERT_EQ(p.x, 4);
    ASSERT_EQ(p.y, 6);
}
