#include <gtest/gtest.h>
#include <span>
#include <ranges>

TEST(span_suite, is_a_range)
{
    std::array numbers{1,2,3,4,5};
    std::span view(numbers);

    std::vector<decltype(numbers)::value_type> resulting;
    for (auto elem: view | std::views::drop(3))
        resulting.push_back(elem);

    ASSERT_EQ(resulting[0], 4);
    ASSERT_EQ(resulting[1], 5);
}
