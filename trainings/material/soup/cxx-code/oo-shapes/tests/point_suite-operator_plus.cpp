#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, operator_plus)
{
    Point p(1,2);
    Point vector(2,3);

    Point new_p = p + vector;      // <--- creates new Point

    ASSERT_EQ(new_p.x(), 3);
    ASSERT_EQ(new_p.y(), 5);
}
