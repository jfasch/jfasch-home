#include <rectangle.h>

#include <sstream>
#include <gtest/gtest.h>

TEST(rectangle_suite, operator_ostream)
{
    const rectangle r(point(3,4), point(8,6));

    std::ostringstream buf;
    buf << r;

    ASSERT_EQ(buf.str(), "((3,4),(8,6))");
}
