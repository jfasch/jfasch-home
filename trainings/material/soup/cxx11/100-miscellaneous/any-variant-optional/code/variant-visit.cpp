#include <gtest/gtest.h>
#include <variant>

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
