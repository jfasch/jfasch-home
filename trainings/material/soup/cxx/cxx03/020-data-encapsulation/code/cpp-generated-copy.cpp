#include <gtest/gtest.h>
#include "point.h"

TEST(cpp_copy_suite, generated_copy_ctor)
{
    point original{1,2};
    point copy1 = original;  // <--- assignment style, but ctor
    point copy2(original);   // <--- c++03 style
    point copy3{original};   // <--- c++11 style

    ASSERT_EQ(copy1.x(), 1);
    ASSERT_EQ(copy1.y(), 2);
    ASSERT_EQ(copy2.x(), 1);
    ASSERT_EQ(copy2.y(), 2);
    ASSERT_EQ(copy3.x(), 1);
    ASSERT_EQ(copy3.y(), 2);
}
