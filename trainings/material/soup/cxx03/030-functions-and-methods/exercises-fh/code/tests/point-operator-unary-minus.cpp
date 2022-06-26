#include <gtest/gtest.h>

#include <point.h>

TEST(point_suite, operator_unary_minus)
{
    const point p{1,2};
    const point minus_p = -p;

    ASSERT_EQ(minus_p.x(), -1);
    ASSERT_EQ(minus_p.y(), -2);
}
