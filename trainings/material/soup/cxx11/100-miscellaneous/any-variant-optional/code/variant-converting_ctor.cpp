#include <gtest/gtest.h>
#include <variant>

TEST(variant_suite, converting_ctor)
{
    std::variant<int, float> v{36.5f};                 // <--- holds float

    ASSERT_FLOAT_EQ(std::get<float>(v), 36.5);
    ASSERT_FLOAT_EQ(std::get<1>(v), 36.5);
    ASSERT_EQ(v.index(), 1);
}
