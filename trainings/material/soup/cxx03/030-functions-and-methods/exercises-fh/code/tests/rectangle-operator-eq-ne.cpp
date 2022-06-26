#include <gtest/gtest.h>

#include <rectangle.h>

TEST(rectangle_suite, operator_eq_ne)
{
    const rectangle r1(point(1,2), point(3,4));
    const rectangle r2(point(1,2), point(3,5));

    bool b;

    b = (r1 == r2);
    ASSERT_FALSE(b);

    b = (r1 == r1);
    ASSERT_TRUE(b);

    b = (r1 != r1);
    ASSERT_FALSE(b);

    b = (r1 != r2);
    ASSERT_TRUE(b);
}
