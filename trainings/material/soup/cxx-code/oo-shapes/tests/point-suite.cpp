#include <point.h>

#include <gtest/gtest.h>


TEST(point_suite, ctor_and_getters)
{
    Point p(1,2);

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}

TEST(point_suite, default_ctor)
{
    Point p;

    ASSERT_EQ(p.x(), 0);
    ASSERT_EQ(p.y(), 0);
}

TEST(point_suite, equal_method)
{
    Point p1(1,2);
    Point p2(1,2);

    ASSERT_TRUE(Point::equal(p1, p2));

    Point p3(1,2);
    Point p4(2,3);

    ASSERT_FALSE(Point::equal(p3, p4));
}

TEST(point_suite, operator_equals)
{
    Point p1(1,2);
    Point p2(1,2);

    ASSERT_TRUE(p1 == p2);

    Point p3(1,2);
    Point p4(2,3);

    ASSERT_FALSE(p3 == p4);
}

TEST(point_suite, operator_equals_const)
{
    const Point p1(1,2);
    const Point p2(1,2);

    ASSERT_TRUE(p1 == p2);

    const Point p3(1,2);
    const Point p4(2,3);

    ASSERT_FALSE(p3 == p4);
}

TEST(point_suite, move_method)
{
    Point p(1,2);
    Point vector(2,3);

    p.move(vector);

    ASSERT_EQ(p.x(), 3);
    ASSERT_EQ(p.y(), 5);
}

TEST(point_suite, operator_plus_equals)
{
    Point p(1,2);
    Point vector(2,3);

    p += vector;

    ASSERT_EQ(p.x(), 3);
    ASSERT_EQ(p.y(), 5);
}

TEST(point_suite, add_method)
{
    Point p(1,2);
    Point vector(2,3);

    Point new_p = Point::add(p, vector);

    ASSERT_EQ(new_p.x(), 3);
    ASSERT_EQ(new_p.y(), 5);
}

TEST(point_suite, operator_plus)
{
    Point p(1,2);
    Point vector(2,3);

    Point new_p = p + vector;

    ASSERT_EQ(new_p.x(), 3);
    ASSERT_EQ(new_p.y(), 5);
}

TEST(point_suite, operator_plus_const)
{
    const Point p(1,2);
    const Point vector(2,3);

    Point new_p = p + vector;

    ASSERT_EQ(new_p.x(), 3);
    ASSERT_EQ(new_p.y(), 5);
}
