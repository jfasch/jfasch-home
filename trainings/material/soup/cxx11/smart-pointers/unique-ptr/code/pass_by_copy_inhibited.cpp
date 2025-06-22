#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

static void foo(std::unique_ptr<BigData> d)            // <-- pass by copy
{
    // ... do something with p
}

TEST(unique_ptr_suite, pass_by_copy_inhibited)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    foo(pdata);                                        // <-- copy initializer inhibited
}
