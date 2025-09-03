#include <gtest/gtest.h>
#include <array>

TEST(array_suite, initialization)
{
    std::array<int, 3> a{100, 101, 102};
    ASSERT_EQ(a[0], 100);
    ASSERT_EQ(a[1], 101);
    ASSERT_EQ(a[2], 102);

    std::array<int, 3> partly{100, 101};
    ASSERT_EQ(partly[0], 100);
    ASSERT_EQ(partly[1], 101);
    ASSERT_EQ(partly[2], 0);
}
