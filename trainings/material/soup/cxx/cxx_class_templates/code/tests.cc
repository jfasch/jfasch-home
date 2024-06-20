#include "point.h"

#include <gtest/gtest.h>
#include <cmath>

#define ASSERT_ALMOST_EQ(l,r) ASSERT_TRUE(std::fabs(l-r) < 0.001)


TEST(CC_Point_Tests, Instantiation)
{
    {
        Point<int> p(1, 2);
        ASSERT_EQ(p.x(), 1);
        ASSERT_EQ(p.y(), 2);
    }
    {
        Point<double> p(1.1, 2.2);
        ASSERT_ALMOST_EQ(p.x(), 1.1);
        ASSERT_ALMOST_EQ(p.y(), 2.2);
    }
}

TEST(CC_Point_Tests, Move)
{
    {
        Point<int> p(1,2);
        Point<int> q = p.move(Point<int>(3,3));

        ASSERT_EQ(p.x(), 4);
        ASSERT_EQ(p.y(), 5);

        ASSERT_EQ(p, q);
    }
    {
        Point<double> p(1.1,2.2);

        ASSERT_DOUBLE_EQ(p.x(), 1.1);
        ASSERT_DOUBLE_EQ(p.y(), 2.2);
    }
}

#if 0 // etc.
TEST(CC_Point_Tests, Move_PlusEquals)
{
    Point p(1,2);
    Point q = (p += Point(3,3));

    ASSERT_EQ(p.x(), 4);
    ASSERT_EQ(p.y(), 5);

    ASSERT_EQ(p, q);
}

TEST(CC_Point_Tests, Add)
{
    Point p(1,2);
    Point q(3,4);

    Point added = p + q;

    ASSERT_EQ(added, Point(4,6));
}

TEST(C_Point_Tests, Equals)
{
    ASSERT_EQ(Point(1,2), Point(1,2));
    ASSERT_NE(Point(1,2), Point(3,4));
}
#endif
