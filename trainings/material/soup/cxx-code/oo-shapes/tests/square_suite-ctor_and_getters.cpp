#include <square.h>
#include <gtest/gtest.h>

TEST(square_suite, ctor_and_getters)
{
    const Square s(Point(1,2), 5); // <--- unmodifiable

    Point bottom_left = s.bottom_left();
    int side_length = s.side_length();

    ASSERT_EQ(bottom_left.x(), 1);
    ASSERT_EQ(bottom_left.y(), 2);
    ASSERT_EQ(side_length, 5);
}
