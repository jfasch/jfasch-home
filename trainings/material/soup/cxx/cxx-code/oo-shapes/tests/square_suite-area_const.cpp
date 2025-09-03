#include <square.h>
#include <gtest/gtest.h>

TEST(square_suite, area_const)
{
    const Square s(Point(1,2), 5); // <--- unmodifiable

    double area = s.area();

    ASSERT_FLOAT_EQ(area, 5*5);
}
