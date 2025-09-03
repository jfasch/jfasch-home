#include <gtest/gtest.h>
#include <string>

TEST(string_suite, find)
{
    std::string s = "Mississippi";
    size_t pos = s.find("ss");
    ASSERT_EQ(pos, 2);

    pos = s.find('s');
    ASSERT_EQ(pos, 2);

    pos = s.find("ss", 3);
    ASSERT_EQ(pos, 5);
}
