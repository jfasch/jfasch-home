#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, distance)
{
    const point3d p1{3,4,5};
    const point3d p2{5,7,8};
    double dst = p1.distance(p2);

    ASSERT_FLOAT_EQ(dst, 4.69041576);
}
