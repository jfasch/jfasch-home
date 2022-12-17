#include <circle.h>

#include <gtest/gtest.h>


TEST(circle_suite, ctor_and_getters)
{
    Circle c(Point(1,2), 5);

    Point center = c.center();
    int radius = c.radius();

    ASSERT_EQ(center.x(), 1);
    ASSERT_EQ(center.y(), 2);
    ASSERT_EQ(radius, 5);
}

// same, using operator==()
TEST(circle_suite, ctor_and_getters_using_operator_equals)
{
    Circle c(Point(1,2), 5);

    ASSERT_TRUE(c.center() == Point(1,2));
}

// pi: either

// * #include <numbers> // c++20
// * static const double pi = 3.14159265358979323846; // in .cpp file

TEST(circle_suite, area)
{
    Circle c(Point(1,2), 5);

    double area = c.area();

    ASSERT_FLOAT_EQ(area, 78.53981634);
}

TEST(circle_suite, area_const)
{
    const Circle c(Point(1,2), 5);

    double area = c.area();

    ASSERT_FLOAT_EQ(area, 78.53981634);
}
