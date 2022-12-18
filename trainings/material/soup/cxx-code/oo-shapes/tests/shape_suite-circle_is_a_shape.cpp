#include <shape.h>
#include <circle.h>
#include <square.h>
#include <gtest/gtest.h>

TEST(shape_suite, circle_is_a_shape)
{
    Circle c(Point(1,2), 5);
    Shape* shape = &c;             // <--- Circle* converted to Shape* because Circle is-a Shape

    (void)shape; // avoid "unused" warning
}
