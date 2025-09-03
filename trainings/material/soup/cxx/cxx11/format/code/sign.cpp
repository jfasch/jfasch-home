#include <format>
#include <gtest/gtest.h>

// sign: + for sign on both negative and positive, - for only negative
TEST(format_suite, sign)
{
    ASSERT_EQ(std::format("{:+6}", 42), "   +42");
    ASSERT_EQ(std::format("{:+6}", -42), "   -42");
    ASSERT_EQ(std::format("{:-6}", 42), "    42");
    ASSERT_EQ(std::format("{:-6}", -42), "   -42");
}
