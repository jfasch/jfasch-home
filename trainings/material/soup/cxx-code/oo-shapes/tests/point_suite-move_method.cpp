#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, move_method)
{
    Point p(1,2);
    Point vector(2,3);

    p.move(vector);

    ASSERT_EQ(p.x(), 3);
    ASSERT_EQ(p.y(), 5);
}
