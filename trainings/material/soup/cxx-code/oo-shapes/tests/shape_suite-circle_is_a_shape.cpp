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
