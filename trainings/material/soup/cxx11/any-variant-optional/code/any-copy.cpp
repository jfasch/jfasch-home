#include <gtest/gtest.h>
#include <any>

TEST(any_suite, copy)
{
    std::any a1 = std::string("howdy");

    std::any a2 = a1;                                  // <--- copy ctor
    ASSERT_EQ(std::any_cast<std::string>(a2), "howdy");

    std::any a3 = std::vector<int>{1, 2, 3, 4, 5, 6};

    a3 = a2;                                           // <--- resource management!

    ASSERT_EQ(std::any_cast<std::string>(a3), "howdy");
}

