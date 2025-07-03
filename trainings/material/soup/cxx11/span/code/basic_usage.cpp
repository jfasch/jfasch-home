#include <gtest/gtest.h>
#include <span>

TEST(span_suite, basic_usage)
{
    std::array numbers{1,2,3,4,5};
    std::span view(numbers);
    ASSERT_EQ(view[2], 3);
    ASSERT_EQ(view.size(), 5);
}
