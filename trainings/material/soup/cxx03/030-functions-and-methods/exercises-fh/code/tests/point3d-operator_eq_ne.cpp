#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, operator_eq_ne)
{
    const point3d p{1,2,3};
    const point3d q{3,4,5};

    bool b;

    b = (p == q);
    ASSERT_FALSE(b);

    b = (p != q);
    ASSERT_TRUE(b);

    b = (p == p);
    ASSERT_TRUE(b);

    b = (p != p);
    ASSERT_FALSE(b);
}
