#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, ctor_and_getters_const)
{
    const Point p(1,2);            // <--- unmodifiable object

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}
