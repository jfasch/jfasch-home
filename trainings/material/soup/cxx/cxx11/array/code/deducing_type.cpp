#include <gtest/gtest.h>
#include <array>

// since c++17?
TEST(array_suite, deducing_type)
{
    std::array a{100, 101};
    static_assert(a.size() == 2);
}
