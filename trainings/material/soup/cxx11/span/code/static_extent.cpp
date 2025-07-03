#include <gtest/gtest.h>
#include <span>

TEST(span_suite, static_extent)
{
    std::array numbers{1,2,3,4,5};                     // <-- 5 at compile time
    std::span span(numbers);
    static_assert(span.extent == 5);                   // <-- constexpr

    if constexpr (span.extent != std::dynamic_extent)
        /*do_something*/;
    else
        /*do_something_else*/;
}
