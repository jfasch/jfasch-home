#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, operator_unary_minus)
{
    const point3d p{1,2,3};
    const point3d minus_p = -p;

    ASSERT_EQ(minus_p.x(), -1);
    ASSERT_EQ(minus_p.y(), -2);
    ASSERT_EQ(minus_p.z(), -3);
}
