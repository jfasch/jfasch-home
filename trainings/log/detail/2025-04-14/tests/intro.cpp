#include <gtest/gtest.h>


TEST(intro, basic)
{
    const char* s1 = "abc";
    const char* s2 = "abc";

    ASSERT_NE(s1, s2);
}
