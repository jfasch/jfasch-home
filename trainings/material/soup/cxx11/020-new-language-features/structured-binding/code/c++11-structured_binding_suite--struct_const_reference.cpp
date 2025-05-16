#include <gtest/gtest.h>

struct point
{
    int x, y;
};

TEST(structured_binding_suite, struct_const_reference)
{
    point p{1,2};

    const auto& [x, y] = p;

    ASSERT_EQ(x, p.x);
    ASSERT_EQ(y, p.y);

    // x, y are *references*, so addresses must match
    ASSERT_EQ(&x, &p.x);
    ASSERT_EQ(&y, &p.y);

    // const reference -> does not compile
    // x = y = 666;
}
