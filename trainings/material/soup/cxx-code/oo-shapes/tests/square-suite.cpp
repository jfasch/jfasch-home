#include <square.h>

#include <gtest/gtest.h>


TEST(square_suite, ctor_and_getters)
{
    Square s(Point(1,2), 5);

    Point bottom_left = s.bottom_left();
    int side_length = s.side_length();

    ASSERT_EQ(bottom_left.x(), 1);
    ASSERT_EQ(bottom_left.y(), 2);
    ASSERT_EQ(side_length, 5);
}

// same, using operator==()
TEST(square_suite, ctor_and_getters_using_operator_equals)
{
    Square s(Point(1,2), 5);

    ASSERT_TRUE(s.bottom_left() == Point(1,2));
}

TEST(square_suite, area)
{
    Square s(Point(1,2), 5);

    double area = s.area();

    ASSERT_FLOAT_EQ(area, 5*5);
}

TEST(square_suite, area_const)
{
    const Square s(Point(1,2), 5);

    double area = s.area();

    ASSERT_FLOAT_EQ(area, 5*5);
}
