#include <gtest/gtest.h>

#include <rectangle.h>

TEST(rectangle_suite, area)
{
    {
        rectangle r;

        ASSERT_EQ(r.width(), 0);
        ASSERT_EQ(r.height(), 0);
        ASSERT_EQ(r.area(), 0);
    }

    {
        rectangle r{point(3,4), point(8,6)};

        ASSERT_EQ(r.width(), 5);
        ASSERT_EQ(r.height(), 2);
        ASSERT_EQ(r.area(), 10);
    }
}
