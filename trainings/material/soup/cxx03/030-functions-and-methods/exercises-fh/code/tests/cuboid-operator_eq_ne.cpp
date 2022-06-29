#include <gtest/gtest.h>
#include <cuboid.h>

TEST(cuboid_suite, operator_eq_ne)
{
    const cuboid c1{point3d{1,2,3}, 4, 5, 6};
    const cuboid c2{point3d{1,2,3}, 4, 5, 7};
    
    bool b;

    b = (c1 == c2);
    ASSERT_FALSE(b);

    b = (c1 != c2);
    ASSERT_TRUE(b);

    b = (c1 == c1);
    ASSERT_TRUE(b);

    b = (c1 != c1);
    ASSERT_FALSE(b);

    ASSERT_NE(c1, cuboid(point3d{2,3,4}, 4, 5, 6));
}
