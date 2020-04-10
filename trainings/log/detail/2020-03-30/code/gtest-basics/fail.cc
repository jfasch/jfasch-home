#include <gtest/gtest.h>
#include <iostream>
// #include <stdio.h>


TEST(FailSuite, Basic) 
{
    FAIL() << "weil ichs kann " << 42;

    // FAIL() is "fatal"; this is why we don't get here.
    const char* i = "zweiundvierzig";
    std::cout << "alles klar, die Antwort ist " << i << std::endl;
}

TEST(FailSuite, Assert_True) 
{
    ASSERT_TRUE('X' == 'U');

    // btw, ASSERT_*() is also fatal
}

TEST(FailSuite, Assert_Eq) 
{
    // same as ASSERT_TRUE('X', 'U'), but the output is more intuitive
    ASSERT_EQ('X', 'U');
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
