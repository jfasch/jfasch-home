#include <gtest/gtest.h>
#include <cuboid.h>

TEST(cuboid_suite, operator_plus)
{
    const cuboid c{point3d{1,2,3}, 4, 5, 6};
    const point3d vec{3,4,5};

    const cuboid c1 = c + vec;

    ASSERT_EQ(c1.front_bottom_left(), point3d(4,6,8));
    ASSERT_EQ(c1.width(), 4);
    ASSERT_EQ(c1.height(), 5);
    ASSERT_EQ(c1.length(), 6);
}
