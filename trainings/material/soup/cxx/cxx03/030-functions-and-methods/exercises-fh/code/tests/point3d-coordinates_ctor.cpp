#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, coordinates_ctor)
{
    const point3d p{1,2,3};

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
    ASSERT_EQ(p.z(), 3);
}
