#include <gtest/gtest.h>

struct point
{
    int x, y;
};

TEST(structured_binding_suite, struct_reference)
{
    point p{1,2};

    auto& [x, y] = p;

    ASSERT_EQ(x, p.x);
    ASSERT_EQ(y, p.y);

    // x, y are *references*, so assignment to those assigns to the
    // *original* struct members
    x = y = 666;
    ASSERT_EQ(p.x, 666);
    ASSERT_EQ(p.y, 666);
}
