#include <gtest/gtest.h>

TEST(structured_binding_suite, tuple_copy)
{
    auto t = std::make_tuple(1, 2, 3);

    auto [x, y, z] = t;

    ASSERT_EQ(x, std::get<0>(t));
    ASSERT_EQ(y, std::get<1>(t));
    ASSERT_EQ(z, std::get<2>(t));

    // x, y, z are *copies*, so original tuple is *not* affected by
    // assignment
    x = y = z = 666;
    ASSERT_NE(std::get<0>(t), 666);
    ASSERT_NE(std::get<1>(t), 666);
    ASSERT_NE(std::get<2>(t), 666);
}
