#include <gtest/gtest.h>
#include <cuboid.h>

TEST(cuboid_suite, operator_ostream)
{
    const cuboid c{point3d{1,2,3}, 4, 5, 6};

    std::ostringstream buf;
    buf << c;

    ASSERT_EQ(buf.str(), "cuboid((1,2,3),w=4,h=5,l=6)");
}
