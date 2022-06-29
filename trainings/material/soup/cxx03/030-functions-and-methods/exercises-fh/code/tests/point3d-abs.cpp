#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, abs)
{
    const point3d p{3,4,5};
    double abs = p.abs();

    ASSERT_FLOAT_EQ(abs, 7.071067812);
}
