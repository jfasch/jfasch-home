#include <gtest/gtest.h>

#include <rectangle.h>

TEST(rectangle_suite, plus_vec)
{
    const rectangle r(point(3,4), point(8,6));
    const point vec(1,2);

    const rectangle r1 = r + vec;

    ASSERT_EQ(r1.bottom_left(), point(4,6));
    ASSERT_EQ(r1.top_right(), point(9,8));

    ASSERT_EQ(r, rectangle(point(3,4), point(8,6)));
}
