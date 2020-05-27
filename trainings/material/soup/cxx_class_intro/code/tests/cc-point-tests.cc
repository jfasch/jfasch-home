#include "../point.h"

#include <gtest/gtest.h>


TEST(CC_Point_Tests, Instantiation)
{
    Point p(1, 2);

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}

TEST(CC_Point_Tests, Move)
{
    Point p(1,2);
    Point q = p.move(Point(3,3));

    ASSERT_EQ(p.x(), 4);
    ASSERT_EQ(p.y(), 5);

    ASSERT_EQ(p, q);
}

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
