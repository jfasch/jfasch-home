#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

void point_init_default(struct point* self)   // <--- "constructor" in C
{
    self->x = 0;
    self->y = 0;
}

TEST(point_c_suite, c_default_constructor_init)
{
    struct point p;                           // <--- uninitialized
    point_init_default(&p);                   // <--- post-birth initialization

    ASSERT_EQ(p.x, 0);
    ASSERT_EQ(p.y, 0);
}
