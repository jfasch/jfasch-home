#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

void point_move(point* self, point vec)
{
    self->x += vec.x;
    self->y += vec.y;
}

TEST(point_c_suite, move)
{
    point p = {1,2};
    const point vec = {3,4};

    point_move(&p, vec);

    ASSERT_EQ(p.x, 4);
    ASSERT_EQ(p.y, 6);
}
