#include <gtest/gtest.h>
#include <string>

TEST(string_suite, substr)
{
    std::string s = "Mississippi";
    std::string is = s.substr(1, /*substring length:*/2);
    ASSERT_EQ(is, "is");
}
