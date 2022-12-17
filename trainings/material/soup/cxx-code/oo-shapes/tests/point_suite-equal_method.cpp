#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, equal_method)
{
    Point p1(1,2);
    Point p2(1,2);

    ASSERT_TRUE(Point::equal(p1, p2));

    Point p3(1,2);
    Point p4(2,3);

    ASSERT_FALSE(Point::equal(p3, p4));
}
