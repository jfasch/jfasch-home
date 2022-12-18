#include <circle.h>
#include <gtest/gtest.h>

// same, using operator==()
TEST(circle_suite, ctor_and_getters_using_operator_equals)
{
    Circle c(Point(1,2), 5);

    ASSERT_TRUE(c.center() == Point(1,2)); // <--- requires Point::operator==()
}
