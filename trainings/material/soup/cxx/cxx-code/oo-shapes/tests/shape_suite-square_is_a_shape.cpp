#include <shape.h>
#include <circle.h>
#include <square.h>
#include <gtest/gtest.h>

TEST(shape_suite, square_is_a_shape)
{
    Square s(Point(1,2), 5);
    Shape* shape = &s;             // <--- Square* converted to Shape* because Square is-a Shape

    (void)shape; // avoid "unused" warning
}
