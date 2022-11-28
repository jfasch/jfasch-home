// bring table:
// https://en.cppreference.com/w/cpp/string/basic_string/to_string
#include <gtest/gtest.h>
#include <string>

TEST(string_suite, convert_from_something)
{
    int i = 42;
    std::string i_str = std::to_string(i);
    ASSERT_EQ(i_str, "42");

    unsigned int ui = 42;
    std::string ui_str = std::to_string(ui);
    ASSERT_EQ(ui_str, "42");

    double d = 42.666;
    std::string d_str = std::to_string(d);
    ASSERT_EQ(d_str, "42.666000");    // sprintf default precision is 6
}
