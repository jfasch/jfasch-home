#include <circle.h>
#include <gtest/gtest.h>

TEST(circle_suite, ctor_and_getters)
{
    const Circle c(Point(1,2), 5);

    Point center = c.center();
    int radius = c.radius();

    ASSERT_EQ(center.x(), 1);
    ASSERT_EQ(center.y(), 2);
    ASSERT_EQ(radius, 5);
}
