#include <gtest/gtest.h>
#include <span>

TEST(span_suite, runtime)
{
    std::vector numbers{1,2,3,4,5};
    std::span view(numbers);
    ASSERT_EQ(view.size(), 5);
}
