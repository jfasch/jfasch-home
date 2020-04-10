#include <gtest/gtest.h>
#include <iostream>

using namespace std;


TEST(NonFatalFailureSuite, Basic) 
{
    EXPECT_TRUE('X' == 'U');
    EXPECT_EQ('X', 'U');
    cout << "Die Antwort ist mir wurscht" << endl;
}
