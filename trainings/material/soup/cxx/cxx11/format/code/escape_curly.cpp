#include <format>
#include <gtest/gtest.h>

TEST(format_suite, escape_curly)
{
    ASSERT_EQ(std::format("{{"), "{");
    ASSERT_EQ(std::format("}}"), "}");
    ASSERT_EQ(std::format("{{}}"), "{}");
}
