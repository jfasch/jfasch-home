#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

point point_add(point lhs, point rhs)
{
    struct point sum;
    sum.x = lhs.x + rhs.x;
    sum.y = lhs.y + rhs.y;
    return sum;
}

point point_sub(point lhs, point rhs)
{
    struct point diff;
    diff.x = lhs.x - rhs.x;
    diff.y = lhs.y - rhs.y;
    return diff;
}

TEST(point_c_suite, add_sub)
{
    const point p = {1,2};
    const point vec = {3,4};

    const point sum = point_add(p, vec);
    ASSERT_EQ(sum.x, 4);
    ASSERT_EQ(sum.y, 6);

    const point diff = point_sub(p, vec);
    ASSERT_EQ(diff.x, -2);
    ASSERT_EQ(diff.y, -2);
}
