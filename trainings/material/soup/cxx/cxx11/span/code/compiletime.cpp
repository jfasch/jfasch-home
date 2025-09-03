#include <gtest/gtest.h>
#include <span>

TEST(span_suite, compiletime)
{
    std::array numbers{1,2,3,4,5};
    std::span view(numbers);
    static_assert(view.size() == 5);
}
