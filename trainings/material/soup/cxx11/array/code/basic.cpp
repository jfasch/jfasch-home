#include <gtest/gtest.h>
#include <array>

TEST(array_suite, basic)
{
    std::array<int, 3> a;                              // <-- uninitialized!
    static_assert(a.size() == 3);                      // <-- known at compile time

    a[1] = 111;
    ASSERT_EQ(a[1], 111);
}
