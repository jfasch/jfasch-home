#include <gtest/gtest.h>
#include <cuboid.h>

TEST(cuboid_suite, surface)
{
    const cuboid c{point3d{1,2,3}, 4, 5, 6};
    ASSERT_EQ(c.surface(), 148);
}
