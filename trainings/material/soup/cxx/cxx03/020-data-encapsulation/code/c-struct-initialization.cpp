#include <gtest/gtest.h>

struct point
{
    int x;
    int y;
};

TEST(point_c_suite, struct_initialization)
{
    struct point p1;            // <--- uninitialized (there be dragons!)
    struct point p2 = {1,2};    // <--- good ol' C "struct initialization"

    ASSERT_EQ(p2.x, 1);
    ASSERT_EQ(p2.y, 2);

    (void)p1; // avoid "unused" warning
}
