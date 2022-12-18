#include <circle.h>
#include <gtest/gtest.h>

TEST(circle_suite, area_const)
{
    const Circle c(Point(1,2), 5); // <--- unmodifiable

    double area = c.area();

    ASSERT_FLOAT_EQ(area, 78.53981634);
}
