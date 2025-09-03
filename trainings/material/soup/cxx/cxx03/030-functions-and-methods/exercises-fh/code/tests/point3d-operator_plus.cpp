#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, operator_plus)
{
    const point3d p{1,2,3};
    const point3d vec{3,4,5};

    const point3d p1 = p + vec;

    ASSERT_EQ(p1.x(), 4);
    ASSERT_EQ(p1.y(), 6);
    ASSERT_EQ(p1.z(), 8);
}
