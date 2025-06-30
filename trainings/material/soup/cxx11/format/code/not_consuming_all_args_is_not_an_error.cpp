#include <format>
#include <gtest/gtest.h>

TEST(format_suite, not_consuming_all_args_is_not_an_error)
{
    ASSERT_EQ(std::format("The answer is {}", 42, "and not 666"), "The answer is 42");
}
