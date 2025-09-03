#include <gtest/gtest.h>
#include "point.h"

TEST(point_cpp_suite, abs)
{
    const point p{3,4};
    double abs = p.abs();

    ASSERT_FLOAT_EQ(abs, 5.0);
}
