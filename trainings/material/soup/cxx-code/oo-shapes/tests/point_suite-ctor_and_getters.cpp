#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, ctor_and_getters)
{
    Point p(1,2);

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}
