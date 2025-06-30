#include <gtest/gtest.h>
#include <array>

TEST(array_suite, constexpr_equality)
{
    constexpr std::array<int, 3> a1 = {200, 201, 202};
    constexpr std::array<int, 3> a2 = {200, 201, 202};

    static_assert(a1 == a2);
}
