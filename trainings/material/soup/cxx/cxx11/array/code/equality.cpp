#include <gtest/gtest.h>
#include <array>

TEST(array_suite, equality)
{
    std::array<int, 3> a1 = {200, 201, 202};
    std::array<int, 3> a2 = {200, 201, 202};

    ASSERT_TRUE(a1 == a2);
}
