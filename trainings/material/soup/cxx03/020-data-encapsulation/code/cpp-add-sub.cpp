#include <gtest/gtest.h>
#include "point.h"

TEST(point_cpp_suite, add_sub)
{
    const point p{1,2};
    const point vec{3,4};

    const point sum = p + vec;
    ASSERT_EQ(sum.x(), 4);
    ASSERT_EQ(sum.y(), 6);

    const point diff = p - vec;
    ASSERT_EQ(diff.x(), -2);
    ASSERT_EQ(diff.y(), -2);
}
