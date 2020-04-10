#include <gtest/gtest.h>
#include <iostream>

using namespace std;


TEST(NonFatalFailureSuite, Basic) 
{
    EXPECT_TRUE('X' == 'U');
    EXPECT_EQ('X', 'U');

    // EXPECT_*() is non-fatal, which is why this statement is
    // executed. the test still fails though.
    cout << "Die Antwort ist mir wurscht" << endl;
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
