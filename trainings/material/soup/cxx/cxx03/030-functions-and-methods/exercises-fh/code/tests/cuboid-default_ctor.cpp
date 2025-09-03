#include <gtest/gtest.h>
#include <cuboid.h>

TEST(cuboid_suite, default_ctor)
{
    const cuboid c;

    ASSERT_EQ(c.front_bottom_left(), point3d(0,0,0));
    ASSERT_EQ(c.width(), 0);
    ASSERT_EQ(c.height(), 0);
    ASSERT_EQ(c.length(), 0);
}
