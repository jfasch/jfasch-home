#include <gtest/gtest.h>

#include <math.h>

struct point
{
    int x;
    int y;
};

double point_abs(const point* self)
{
    int hyp = self->x * self->x + self->y * self->y;
    return sqrt(hyp);
}

TEST(point_c_suite, abs)
{
    const point p = {3,4};
    double abs = point_abs(&p);

    ASSERT_FLOAT_EQ(abs, 5.0);
}
