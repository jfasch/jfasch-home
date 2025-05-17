#include <gtest/gtest.h>
#include <any>

TEST(any_suite, pointer_cast)
{
    std::any a = 42;

    ASSERT_NE(std::any_cast<int>(&a), nullptr);
    ASSERT_EQ(std::any_cast<const double>(&a), nullptr);
}
