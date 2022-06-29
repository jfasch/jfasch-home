#include <gtest/gtest.h>
#include <point3d.h>

TEST(point3d_suite, operator_ostream)
{
    const point3d p{1,2,3};

    std::ostringstream buf;
    buf << p;

    ASSERT_EQ(buf.str(), "(1,2,3)");
}
