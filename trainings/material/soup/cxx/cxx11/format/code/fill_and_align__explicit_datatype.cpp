#include <format>
#include <gtest/gtest.h>

TEST(format_suite, fill_and_align__explicit_datatype)
{
    char c = 'x'; // ascii 120

    // str left
    ASSERT_EQ(std::format("{:6}", c), "x     ");

    // interpret as int -> right
    ASSERT_EQ(std::format("{:6d}", c), "   120");
}
