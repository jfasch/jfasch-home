#include <gtest/gtest.h>

#include "string-10.h"

TEST(string_move_suite, basic)
{
    String s("Hello");
    ASSERT_EQ(s.size(), 5);
    ASSERT_EQ(strcmp(s.c_str(), "Hello"), 0);
}
