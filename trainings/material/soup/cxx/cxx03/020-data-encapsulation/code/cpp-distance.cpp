#include <gtest/gtest.h>
#include "point.h"

TEST(point_cpp_suite, distance)
{
    const point p1{3,4};
    const point p2{5,7};
    double dst = p1.distance(p2);

    ASSERT_FLOAT_EQ(dst, sqrt(13));
}
