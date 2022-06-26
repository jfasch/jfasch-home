#include <gtest/gtest.h>

#include <point.h>

TEST(point_suite, xy)
{
    {
        const point p;
        ASSERT_EQ(p.x(), 0);
        ASSERT_EQ(p.y(), 0);
    }
    {
        const point p{1,2};
        ASSERT_EQ(p.x(), 1);
        ASSERT_EQ(p.y(), 2);
    }
}
