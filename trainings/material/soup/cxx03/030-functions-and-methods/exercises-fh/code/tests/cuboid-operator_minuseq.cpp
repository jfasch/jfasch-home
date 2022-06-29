#include <gtest/gtest.h>
#include <cuboid.h>

TEST(cuboid_suite, operator_minuseq)
{
    cuboid c{point3d{1,2,3}, 4, 5, 6};
    const point3d vec{3,4,5};

    const cuboid& c1 = c -= vec;

    ASSERT_EQ(c.front_bottom_left(), point3d(-2,-2,-2));
    ASSERT_EQ(c.width(), 4);
    ASSERT_EQ(c.height(), 5);
    ASSERT_EQ(c.length(), 6);

    bool b = (c == c1);
    ASSERT_TRUE(b);

    ASSERT_EQ(&c1, &c);  // operator-=() returns cuboid& !!
}
