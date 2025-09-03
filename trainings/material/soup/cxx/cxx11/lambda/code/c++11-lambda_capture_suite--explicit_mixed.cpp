#include <gtest/gtest.h>

TEST(lambda_capure_suite, explicit_mixed)
{
    int x = 1, y = 2;

    auto fun = [&x, y](){   // x by reference, y by copy
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 4);

    y = 3;
    ASSERT_EQ(fun(), 4);
}
