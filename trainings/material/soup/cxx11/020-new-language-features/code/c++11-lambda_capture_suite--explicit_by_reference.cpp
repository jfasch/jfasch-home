#include <gtest/gtest.h>

TEST(lambda_capure_suite, explicit_by_reference)
{
    int x = 1, y = 2;

    auto fun = [&x, &y](){
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 4);
}
