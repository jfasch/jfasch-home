#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, default_ctor)
{
    Point p;

    ASSERT_EQ(p.x(), 0);
    ASSERT_EQ(p.y(), 0);
}
