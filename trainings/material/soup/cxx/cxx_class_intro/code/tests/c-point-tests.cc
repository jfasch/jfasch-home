#include "../c-point.h"

#include <gtest/gtest.h>


TEST(C_Point_Tests, Instantiation)
{
    struct point p = {1,2};

    ASSERT_EQ(p.x, 1);
    ASSERT_EQ(p.y, 2);
}
TEST(C_Point_Tests, Instantiation_Func)
{
    struct point p = point_create(1,2);

    ASSERT_EQ(p.x, 1);
    ASSERT_EQ(p.y, 2);
}

TEST(C_Point_Tests, Move)
{
    struct point p = {1,2};
    p.x += 3;
    p.y += 3;

    ASSERT_EQ(p.x, 4);
    ASSERT_EQ(p.y, 5);
}
TEST(C_Point_Tests, Move_Func)
{
    struct point p = point_create(1,2);
    point_move(&p, point_create(3,3));

    ASSERT_EQ(p.x, 4);
    ASSERT_EQ(p.y, 5);
}

TEST(C_Point_Tests, Add)
{
    struct point p = {1,2};
    struct point q = {3,4};

    struct point added = {p.x+q.x, p.y+q.y}; // this is not C!

    ASSERT_EQ(added.x, 4);
    ASSERT_EQ(added.y, 6);
}
TEST(C_Point_Tests, Add_Func)
{
    struct point p = point_create(1,2);
    struct point q = point_create(3,4);

    struct point added = point_add(p, q);

    ASSERT_EQ(added.x, 4);
    ASSERT_EQ(added.y, 6);
}

TEST(C_Point_Tests, Compare_Func)
{
    ASSERT_TRUE(point_compare(point_create(1,2), point_create(1,2)));
    ASSERT_FALSE(point_compare(point_create(1,2), point_create(3,4)));
}
