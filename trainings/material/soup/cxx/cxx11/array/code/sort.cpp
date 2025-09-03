#include <gtest/gtest.h>
#include <array>

TEST(array_suite, sort)
{
    std::array<int, 3> a = {200, 204, 203};
    std::sort(a.begin(), a.end());

    ASSERT_EQ(a[0], 200);
    ASSERT_EQ(a[1], 203);
    ASSERT_EQ(a[2], 204);
}
