#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, operator_pluseq)
{
    point3d p{1,2,3};
    const point3d vec{3,4,5};
    const point3d& p1 = p += vec;

    ASSERT_EQ(p.x(), 4);
    ASSERT_EQ(p.y(), 6);
    ASSERT_EQ(p.z(), 8);

    bool b = (p == p1);
    ASSERT_TRUE(b);

    ASSERT_EQ(&p1, &p);  // operator+=() returns point3d& !!
}
