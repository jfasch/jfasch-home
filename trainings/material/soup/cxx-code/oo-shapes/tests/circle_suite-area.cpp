#include <circle.h>
#include <gtest/gtest.h>

TEST(circle_suite, area)
{
    Circle c(Point(1,2), 5);

    double area = c.area();

    ASSERT_FLOAT_EQ(area, 78.53981634);
}
