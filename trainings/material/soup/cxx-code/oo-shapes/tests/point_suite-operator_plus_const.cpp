#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, operator_plus_const)
{
    const Point p(1,2);
    const Point vector(2,3);

    Point new_p = p + vector;

    ASSERT_EQ(new_p.x(), 3);
    ASSERT_EQ(new_p.y(), 5);
}
