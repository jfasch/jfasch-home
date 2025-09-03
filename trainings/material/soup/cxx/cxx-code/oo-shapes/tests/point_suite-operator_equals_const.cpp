#include <point.h>
#include <gtest/gtest.h>

TEST(point_suite, operator_equals_const)
{
    const Point p1(1,2);           // <--- unmodifiable
    const Point p2(1,2);           // <--- unmodifiable

    ASSERT_TRUE(p1 == p2);

    const Point p3(1,2);           // <--- unmodifiable
    const Point p4(2,3);           // <--- unmodifiable

    ASSERT_FALSE(p3 == p4);
}
