#include <gtest/gtest.h>

TEST(structured_binding_suite, tuple_const_reference)
{
    auto t = std::make_tuple(1, 2, 3);

    const auto& [x, y, z] = t;

    ASSERT_EQ(x, std::get<0>(t));
    ASSERT_EQ(y, std::get<1>(t));
    ASSERT_EQ(z, std::get<2>(t));

    // x, y, z are *const references*, so compiler doesn't let me
    // assign ("assignment of read-only reference")

    // x = y = z = 666;  <--- does not compile

    // but lets make sure that x, y, z are still *references* -> the
    // addresses must match
    ASSERT_EQ(&x, &std::get<0>(t));
    ASSERT_EQ(&y, &std::get<1>(t));
    ASSERT_EQ(&z, &std::get<2>(t));
}
