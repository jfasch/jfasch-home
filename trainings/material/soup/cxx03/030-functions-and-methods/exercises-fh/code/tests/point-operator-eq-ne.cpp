#include <gtest/gtest.h>

#include <point.h>

TEST(point_suite, operator_eq_ne)
{
    const point p{1,2};
    const point q{3,4};

    bool b;

    b = (p == q);
    ASSERT_FALSE(b);

    b = (p == p);
    ASSERT_TRUE(b);

    b = (p != p);
    ASSERT_FALSE(b);

    b = (p != q);
    ASSERT_TRUE(b);
}

