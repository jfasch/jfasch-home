#include <gtest/gtest.h>

#include <rectangle.h>

TEST(rectangle_suite, coordinates)
{
    {
        const rectangle r;
        ASSERT_EQ(r.bottom_left(), point(0,0));
        ASSERT_EQ(r.top_right(), point(0,0));
        ASSERT_EQ(r.top_left(), point(0,0));
        ASSERT_EQ(r.bottom_right(), point(0,0));
    }

    {
        const point bottom_left{1,2};
        const point top_right{8,6};
        const rectangle r{bottom_left, top_right};

        ASSERT_EQ(r.bottom_left(), point(1,2));
        ASSERT_EQ(r.top_right(), point(8,6));
        ASSERT_EQ(r.top_left(), point(1,6));
        ASSERT_EQ(r.bottom_right(), point(8,2));
    }
}
