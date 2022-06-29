#include <gtest/gtest.h>
#include "point.h"

TEST(point_cpp_suite, move)
{
    point p{1,2};
    const point vec{3,4};
    const point& p1 = p += vec;

    ASSERT_EQ(p.x(), 4);
    ASSERT_EQ(p.y(), 6);

    bool b = (p == p1);
    ASSERT_TRUE(b);

    ASSERT_EQ(&p1, &p);  // operator+=() returns point& !!
}
