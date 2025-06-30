#include <gtest/gtest.h>
#include <array>

TEST(array_suite, copy)
{
    std::array<int, 3> a1{100, 101};
    std::array<int, 3> a2{200, 201, 202};

    a1 = a2;
    ASSERT_EQ(a1[0], 200);
    ASSERT_EQ(a1[1], 201);
    ASSERT_EQ(a1[2], 202);
}
