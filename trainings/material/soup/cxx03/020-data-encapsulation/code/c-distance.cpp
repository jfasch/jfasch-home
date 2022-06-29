#include <gtest/gtest.h>

#include <math.h>

struct point
{
    int x;
    int y;
};

double point_distance(point lhs, point rhs)
{
    int a = rhs.x - lhs.x;
    int b = rhs.y - lhs.y;
    return sqrt(a*a + b*b);
}

TEST(point_c_suite, distance)
{
    const point p1 = {3,4};
    const point p2 = {5,7};
    double dst = point_distance(p1, p2);

    ASSERT_FLOAT_EQ(dst, sqrt(13));
}
