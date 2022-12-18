#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, ctor_and_getters)
{
    Point p(1,2);                  // <--- constructor that take x and y parameters

    ASSERT_EQ(p.x(), 1);           // <--- getter for x coordinate
    ASSERT_EQ(p.y(), 2);           // <--- getter for y coordinate
}
