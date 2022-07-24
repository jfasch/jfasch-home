#include <gtest/gtest.h>

struct point
{
    point(int x, int y)        // <--- explicit ctor, 2 parameters
    : x{x}, y{y} {}

    int x;
    int y;
};

TEST(brace_initialization_suite, basic)
{
    point p1(1,2);             // <--- explicitly using explicit ctor
    point p2{3,4};             // <--- implicitly using explicit ctor (no initializer_list ctor found)

    ASSERT_EQ(p1.x, 1);
    ASSERT_EQ(p1.y, 2);
    ASSERT_EQ(p2.x, 3);
    ASSERT_EQ(p2.y, 4);
}
