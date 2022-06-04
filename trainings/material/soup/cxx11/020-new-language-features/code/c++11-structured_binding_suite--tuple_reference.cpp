#include <gtest/gtest.h>

TEST(structured_binding_suite, tuple_reference)
{
    auto t = std::make_tuple(1, 2, 3);

    auto& [x, y, z] = t;

    ASSERT_EQ(x, std::get<0>(t));
    ASSERT_EQ(y, std::get<1>(t));
    ASSERT_EQ(z, std::get<2>(t));

    // x, y, z are *reference*, so assignment to those goes into the
    // *original* tuple members
    x = y = z = 666;
    ASSERT_EQ(std::get<0>(t), 666);
    ASSERT_EQ(std::get<1>(t), 666);
    ASSERT_EQ(std::get<2>(t), 666);
}
