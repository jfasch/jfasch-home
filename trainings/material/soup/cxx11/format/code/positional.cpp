#include <format>
#include <gtest/gtest.h>

TEST(format_suite, positional)
{
    ASSERT_EQ(std::format("The answer is {0}, evil {1}, answer again {0}", 42, 666), "The answer is 42, evil 666, answer again 42");
}
