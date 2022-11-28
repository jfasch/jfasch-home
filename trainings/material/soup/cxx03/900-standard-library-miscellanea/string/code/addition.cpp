#include <gtest/gtest.h>
#include <string>

TEST(string_suite, addition)
{
    std::string hello = "Hello";
    std::string who = "Joerg";
    
    std::string greeting1 = hello + " " + who;  // <--- inefficient
    ASSERT_EQ(greeting1, "Hello Joerg");

    std::string greeting2 = hello;
    greeting2 += ' ';                           // <--- a little better
    greeting2 += who;                           // <--- a little better
}
