#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, default_ctor)
{
    const point3d p;

    ASSERT_EQ(p.x(), 0);
    ASSERT_EQ(p.y(), 0);
    ASSERT_EQ(p.z(), 0);
}
