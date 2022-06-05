#include <gtest/gtest.h>

TEST(lambda_capure_suite, all_by_copy)
{
    int x = 1, y = 2;

    auto fun = [=](){   // <-- all by reference
        return x + y;
    };

    ASSERT_EQ(fun(), 3);

    x = 2;
    ASSERT_EQ(fun(), 3);
}
