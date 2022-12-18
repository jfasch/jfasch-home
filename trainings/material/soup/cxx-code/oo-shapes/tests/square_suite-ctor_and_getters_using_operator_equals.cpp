#include <square.h>
#include <gtest/gtest.h>

// same, using operator==()
TEST(square_suite, ctor_and_getters_using_operator_equals)
{
    Square s(Point(1,2), 5);

    ASSERT_TRUE(s.bottom_left() == Point(1,2)); // <--- requires Point::operator==()
}
