#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, default_ctor)
{
    Point p;                       // <--- default ctor used to initialize object

    ASSERT_EQ(p.x(), 0);           // <--- not initializing a Point gives origin
    ASSERT_EQ(p.y(), 0);
}
