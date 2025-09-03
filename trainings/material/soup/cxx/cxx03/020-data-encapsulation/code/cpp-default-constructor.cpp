#include <gtest/gtest.h>
#include "point.h"

TEST(point_cpp_suite, default_constructor)
{
    point p;

    ASSERT_EQ(p.x(), 0);
    ASSERT_EQ(p.y(), 0);
}
