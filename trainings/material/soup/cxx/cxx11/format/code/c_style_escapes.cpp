#include <format>
#include <gtest/gtest.h>

TEST(format_suite, c_style_escapes)
{
    ASSERT_EQ(std::format("\t\n\\"), "\t\n\\");
}
