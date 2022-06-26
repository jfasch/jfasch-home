#include <gtest/gtest.h>

TEST(exercises_fh_suite, point_xy)
{
    const point p{1,2};
    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}

TEST(exercises_fh_suite, point_eq_ne)
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

TEST(exercises_fh_suite, point_pluseq)
{
    point p{1,2};
    const point vec{3,4};
    const point& p1 = p += vec;

    ASSERT_EQ(p.x(), 4);
    ASSERT_EQ(p.y(), 6);

    bool b = (p == p1);
    ASSERT_TRUE(b);

    ASSERT_EQ(&p1, &p);  // operator+=() return point&
}

TEST(exercises_fh_suite, point_plus)
{
    const point p{1,2};
    const point vec{3,4};

    const point p1 = p + vec;

    ASSERT_EQ(p1.x(), 4);
    ASSERT_EQ(p1.y(), 6);
}

TEST(exercises_fh_suite, point_unary_minus)
{
    const point p{1,2};
    const point minus_p = -p;

    ASSERT_EQ(minus_p.x(), -1);
    ASSERT_EQ(minus_p.y(), -2);
}

