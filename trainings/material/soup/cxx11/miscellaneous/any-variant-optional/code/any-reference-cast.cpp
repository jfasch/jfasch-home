#include <gtest/gtest.h>
#include <any>

TEST(any_suite, reference_cast)
{
    std::any a = 42;
    int& i = std::any_cast<int&>(a);                   // <--- pointer to any-content

    i = 666;                                           // <--- modify a
    ASSERT_EQ(std::any_cast<int>(a), 666);             // <--- a has been modified
}

