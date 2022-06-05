#include <gtest/gtest.h>

TEST(lambda_capure_suite, initialized_capture)
{
    auto fun = [x=1, y=2](){
        return x + y;
    };

    ASSERT_EQ(fun(), 3);
}
