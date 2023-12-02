#include <gtest/gtest.h>
#include <variant>

TEST(variant_suite, bad_access)
{
    std::variant<int, float> v{42};

    try {
        std::get<float>(v);
    }
    catch (const std::bad_variant_access&) {}
}
