#include <gtest/gtest.h>
#include <variant>

TEST(variant_suite, default_ctor)
{
    std::variant<int, float> v;

    // first variant, default-initialized
    ASSERT_EQ(std::get<int>(v), 0);
    ASSERT_EQ(std::get<0>(v), 0);
    ASSERT_EQ(v.index(), 0);
    ASSERT_TRUE(std::holds_alternative<int>(v));

    v = 36.5f;

    ASSERT_FLOAT_EQ(std::get<float>(v), 36.5);
    ASSERT_FLOAT_EQ(std::get<1>(v), 36.5);
    ASSERT_EQ(v.index(), 1);
    ASSERT_TRUE(std::holds_alternative<float>(v));
}

TEST(variant_suite, converting_ctor)
{
    std::variant<int, float> v{36.5f};

    ASSERT_FLOAT_EQ(std::get<float>(v), 36.5);
    ASSERT_FLOAT_EQ(std::get<1>(v), 36.5);
    ASSERT_EQ(v.index(), 1);
}

struct Visitor
{
    Visitor() : int_seen{false}, float_seen{false} {}
    void operator()(int) { int_seen = true; }
    void operator()(float) { float_seen = true; }
    bool int_seen, float_seen;
};

TEST(variant_suite, visit)
{
    std::variant<int, float> v;

    Visitor vis;

    std::visit(vis, v);
    ASSERT_TRUE(vis.int_seen);

    v = 36.5f;
}
