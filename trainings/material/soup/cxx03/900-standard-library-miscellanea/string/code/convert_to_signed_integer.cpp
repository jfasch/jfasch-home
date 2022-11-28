// file:///tmp/jfasch-home/html/trainings/material/soup/c/020-types-operators-expressions/080-type-conversions/topic.html

// stol -> long
// stoll -> long long
#include <gtest/gtest.h>
#include <string>

TEST(string_suite, convert_to_signed_integer)
{
    {
        std::string numstr = "42";
        int answer = std::stoi(numstr);
        ASSERT_EQ(answer, 42);
    }
    {
        std::string numstr = "42";
        int answer = std::stoi(numstr, /*start pos*/0, /*base*/16);
        ASSERT_EQ(answer, 66);
    }
}

