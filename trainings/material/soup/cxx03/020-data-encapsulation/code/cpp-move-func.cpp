#include <gtest/gtest.h>
#include "point.h"

TEST(point_cpp_suite, move_func)
{
    point p{1,2};

    p.move(3,4);

    ASSERT_EQ(p.x(), 4);
    ASSERT_EQ(p.y(), 6);
}
