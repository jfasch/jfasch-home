#include <circle.h>
#include <gtest/gtest.h>

// pi: either

// * #include <numbers> // c++20
// * static const double pi = 3.14159265358979323846; // in .cpp file

TEST(circle_suite, area)
{
    Circle c(Point(1,2), 5);

    double area = c.area();

    ASSERT_FLOAT_EQ(area, 78.53981634);
}
