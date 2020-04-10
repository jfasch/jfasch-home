#include <gtest/gtest.h>
#include <iostream>


TEST(FailSuite, Basic) 
{
    FAIL() << "weil ichs kann " << 42;

    const char* i = "zweiundvierzig";
    std::cout << "alles klar, die Antwort ist " << i << std::endl;
}

TEST(FailSuite, Assert_True) 
{
    ASSERT_TRUE('X' == 'U');
}

TEST(FailSuite, Assert_Eq) 
{
    ASSERT_EQ('X', 'U');
}
