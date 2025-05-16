#include <gtest/gtest.h>

TEST(brace_initialization_suite, narrowing)
{
    int i{1.2};
}
