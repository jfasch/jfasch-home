#include <sstream>
#include <gtest/gtest.h>

#include <point.h>

TEST(point_suite, operator_ostream)
{
    const point p{1,2};

    std::ostringstream buf;
    buf << p;

    ASSERT_EQ(buf.str(), "(1,2)");
}
