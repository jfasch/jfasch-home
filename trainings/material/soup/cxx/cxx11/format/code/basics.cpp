#include <format>
#include <gtest/gtest.h>

TEST(format_suite, basics)
{
    ASSERT_EQ(std::format("The answer is {}", 42), "The answer is 42");

    ASSERT_EQ(std::format("There are two answers: {} and {}", 42, 7), "There are two answers: 42 and 7");

    // same with more syntax, but omitting position and formatting parameters
    ASSERT_EQ(std::format("The answer is {:}", 42), "The answer is 42");
}
