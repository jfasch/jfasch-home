#include <format>
#include <gtest/gtest.h>

TEST(format_suite, hash_integral)
{
    ASSERT_EQ(std::format("{:#x}", 42), "0x2a");
    ASSERT_EQ(std::format("{:#d}", 42), "42"); // default, same as :d
    ASSERT_EQ(std::format("{:#o}", 42), "052");
    ASSERT_EQ(std::format("{:#b}", 42), "0b101010");

    ASSERT_EQ(std::format("{:#6x}", 42), "  0x2a");
    ASSERT_EQ(std::format("{:6d}", 42), "    42");
    ASSERT_EQ(std::format("{:#6b}", 42), "0b101010"); // longer than 6
}
