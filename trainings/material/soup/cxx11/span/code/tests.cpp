#include <gtest/gtest.h>
#include <span>

TEST(span_suite, basic)
{
    std::vector<int> numbers{1,2,3,4,5};
    std::span span1(numbers);
    ASSERT_EQ(span1.size(), 5);
}
