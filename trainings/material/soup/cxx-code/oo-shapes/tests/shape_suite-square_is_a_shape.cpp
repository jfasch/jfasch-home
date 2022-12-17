#include <shape.h>
#include <circle.h>
#include <square.h>
#include <gtest/gtest.h>

TEST(shape_suite, square_is_a_shape)
{
    Square s(Point(1,2), 5);
    Shape* shape = &s;

    (void)shape; // avoid "unused" warning
}
