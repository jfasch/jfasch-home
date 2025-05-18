#include <gtest/gtest.h>

#include <array>
#include <algorithm>


TEST(array_suite, basic)
{
    std::array<int, 5> a;
    ASSERT_EQ(a.size(), 5);

    a[1] = 111;
    int value = a[1];

    ASSERT_EQ(value, 111);
}

TEST(array_suite, initialization)
{
    std::array<int, 5> a = {100, 101};
    ASSERT_EQ(a.size(), 5);

    ASSERT_EQ(a[0], 100);
    ASSERT_EQ(a[1], 101);
    ASSERT_EQ(a[2], 0);
    ASSERT_EQ(a[3], 0);
    ASSERT_EQ(a[4], 0);
}

TEST(array_suite, assignment)
{
    std::array<int, 5> a1 = {100, 101};
    std::array<int, 5> a2 = {200, 201, 202, 203, 204};

    a1 = a2;
    ASSERT_EQ(a1[0], 200);
    ASSERT_EQ(a1[1], 201);
    ASSERT_EQ(a1[2], 202);
    ASSERT_EQ(a1[3], 203);
    ASSERT_EQ(a1[4], 204);
}

TEST(array_suite, equality)
{
    std::array<int, 5> a1 = {200, 201, 202, 203, 204};
    std::array<int, 5> a2 = {200, 201, 202, 203, 204};

    ASSERT_TRUE(a1 == a2);
}

TEST(array_suite, sort)
{
    std::array<int, 5> a = {200, 204, 203, 202, 201};
    std::sort(a.begin(), a.end());

    ASSERT_EQ(a[0], 200);
    ASSERT_EQ(a[1], 201);
    ASSERT_EQ(a[2], 202);
    ASSERT_EQ(a[3], 203);
    ASSERT_EQ(a[4], 204);
}

TEST(array_suite, empty)
{
    std::array<int, 0> a0 = {};
    ASSERT_TRUE(a0.empty());
    ASSERT_EQ(a0.size(), 0);

    std::array<int, 5> a5 = {};
    ASSERT_EQ(a5.size(), 5);
}

