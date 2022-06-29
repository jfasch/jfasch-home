#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

int /*bool*/ point_equal(point lhs, point rhs)
{
    return
        lhs.x == rhs.x &&
        lhs.y == rhs.y;
}
int /*bool*/ point_not_equal(point lhs, point rhs)
{
    return ! point_equal(lhs, rhs);
}

TEST(point_c_suite, eq_ne)
{
    const struct point p = {1,2};
    const struct point q = {3,4};

    int b;

    b = point_equal(p, q);
    ASSERT_FALSE(b);

    b = point_equal(p, p);
    ASSERT_TRUE(b);

    b = point_not_equal(p, p);
    ASSERT_FALSE(b);

    b = point_not_equal(p, q);
    ASSERT_TRUE(b);
}
