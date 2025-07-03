#include <gtest/gtest.h>
#include <span>

TEST(span_suite, dynamic_extent)
{
    std::vector numbers{1,2,3,4,5};                    // <-- 5 at runtime
    std::span span(numbers);
    static_assert(span.extent == std::dynamic_extent); // <-- constexpr
    if constexpr (span.extent != std::dynamic_extent)
        /*do_something*/;
    else
        /*do_something_else*/;
}
