#include <gtest/gtest.h>
#include <array>

TEST(array_suite, range_for)
{
    std::array<int, 3> a = {200, 204, 203};
    for (int _: a)
        /*do something with elem*/;
}
