#include <gtest/gtest.h>
#include <variant>

TEST(variant_suite, default_ctor)
{
    std::variant<int, float> v;                        // <--- default: int{}

    ASSERT_EQ(std::get<int>(v), 0);                    // <--- by-type: does not fail
    ASSERT_EQ(std::get<0>(v), 0);                      // <--- by-position
    ASSERT_EQ(v.index(), 0);                           // <--- which position does it hold?
    ASSERT_TRUE(std::holds_alternative<int>(v));       // <--- which type does it hold?

    v = 36.5f;                                         // <--- now has float
                                                       // ...
    ASSERT_FLOAT_EQ(std::get<float>(v), 36.5);
    ASSERT_FLOAT_EQ(std::get<1>(v), 36.5);
    ASSERT_EQ(v.index(), 1);
    ASSERT_TRUE(std::holds_alternative<float>(v));
}
