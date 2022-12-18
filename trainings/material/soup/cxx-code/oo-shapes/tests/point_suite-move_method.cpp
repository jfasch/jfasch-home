#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, move_method)
{
    Point p(1,2);
    const Point vector(2,3);       // <--- unmodifiable

    p.move(vector);                // <--- modifies p, but not vector

    ASSERT_EQ(p.x(), 3);
    ASSERT_EQ(p.y(), 5);
}
