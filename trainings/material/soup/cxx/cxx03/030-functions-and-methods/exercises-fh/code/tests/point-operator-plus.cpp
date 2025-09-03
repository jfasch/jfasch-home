#include <gtest/gtest.h>

#include <point.h>

TEST(point_suite, operator_plus)
{
    const point p{1,2};
    const point vec{3,4};

    const point p1 = p + vec;

    ASSERT_EQ(p1.x(), 4);
    ASSERT_EQ(p1.y(), 6);
}
