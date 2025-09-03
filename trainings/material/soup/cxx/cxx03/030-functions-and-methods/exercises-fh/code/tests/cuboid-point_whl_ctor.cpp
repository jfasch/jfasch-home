#include <gtest/gtest.h>
#include <cuboid.h>

TEST(cuboid_suite, point_whl_ctor)
{
    const cuboid c{point3d{1,2,3}, 4, 5, 6};

    ASSERT_EQ(c.front_bottom_left(), point3d(1,2,3));
    ASSERT_EQ(c.width(), 4);
    ASSERT_EQ(c.height(), 5);
    ASSERT_EQ(c.length(), 6);
}
