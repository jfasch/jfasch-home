#include <gtest/gtest.h>
#include <string>

TEST(string_suite, initialization)
{
    std::string hello("Hello");                 // <--- "const char*" ctor 
    std::string another_hello = hello;          // <--- copy ctor
    std::string who = "Joerg";                  // <--- "const char*" ctor (assignment style)
}
