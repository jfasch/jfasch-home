#include <gtest/gtest.h>
#include <variant>

struct Foo
{
    Foo() = delete;
    Foo(void*) {}
};

TEST(variant_suite, no_default_ctor)
{
    // std::variant<Foo> v;                            // <--- error: no default ctor
    std::variant<Foo> v{nullptr};                      // <--- OK

    (void)v;
}
