#include <shape.h>
#include <circle.h>
#include <square.h>
#include <gtest/gtest.h>

TEST(shape_suite, area_is_shape_functionality__square)
{
    Square s(Point(1,2), 5);
    Shape* shape = &s;

    double area = shape->area();

    ASSERT_FLOAT_EQ(area, 5*5);
}
