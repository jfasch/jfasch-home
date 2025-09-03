#include <gtest/gtest.h>
#include "point.h"

TEST(point_cpp_suite, constructor_coordinates)
{
    point p1{3,4};    // <--- c++11 "brace initialization" style
    ASSERT_EQ(p1.x(), 3);
    ASSERT_EQ(p1.y(), 4);

    point p2(3,4);    // <--- good-ol' c++03 style
    ASSERT_EQ(p2.x(), 3);
    ASSERT_EQ(p2.y(), 4);
}
