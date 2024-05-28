#include <gtest/gtest.h>
#include <string>

TEST(string_suite, convert_to_unsigned_integer)
{
    {
        std::string numstr = "42";
        unsigned long answer = std::stoul(numstr);
        ASSERT_EQ(answer, 42);
    }
    {
        std::string numstr = "-42";
        unsigned long answer = std::stoul(numstr); // <--- for sure not negative
        (void)answer;
    }
}
