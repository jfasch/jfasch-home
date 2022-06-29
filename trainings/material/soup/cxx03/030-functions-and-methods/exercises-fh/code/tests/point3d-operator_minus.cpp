#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, operator_minus)
{
    const point3d p{1,2,3};
    const point3d vec{3,4,5};

    const point3d p1 = p - vec;

    ASSERT_EQ(p1.x(), -2);
    ASSERT_EQ(p1.y(), -2);
    ASSERT_EQ(p1.z(), -2);
}
