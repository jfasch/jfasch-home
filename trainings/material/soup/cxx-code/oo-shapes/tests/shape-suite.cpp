#include <shape.h>
#include <circle.h>
#include <square.h>

#include <gtest/gtest.h>


TEST(shape_suite, circle_is_a_shape)
{
    Circle c(Point(1,2), 5);
    Shape* shape = &c;

    (void)shape; // avoid "unused" warning
}

TEST(shape_suite, square_is_a_shape)
{
    Square s(Point(1,2), 5);
    Shape* shape = &s;

    (void)shape; // avoid "unused" warning
}

TEST(shape_suite, area_is_shape_functionality__circle)
{
    Circle c(Point(1,2), 5);
    Shape* shape = &c;

    double area = shape->area();

    ASSERT_FLOAT_EQ(area, 78.53981634);
}

TEST(shape_suite, area_is_shape_functionality__square)
{
    Square s(Point(1,2), 5);
    Shape* shape = &s;

    double area = shape->area();

    ASSERT_FLOAT_EQ(area, 5*5);
}
