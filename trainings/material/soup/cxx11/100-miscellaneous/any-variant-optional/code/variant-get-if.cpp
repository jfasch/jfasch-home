#include <gtest/gtest.h>
#include <variant>

TEST(variant_suite, get_if)
{
    int tmp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    (void)tmp;
    std::variant<int, float> v{42};

    const int* pi = std::get_if<int>(& /*REALLY!*/ v);
    ASSERT_NE(pi, nullptr);
    ASSERT_EQ(*pi, 42);

    const float* pf = std::get_if<float>(&v);
    ASSERT_EQ(pf, nullptr);
}
