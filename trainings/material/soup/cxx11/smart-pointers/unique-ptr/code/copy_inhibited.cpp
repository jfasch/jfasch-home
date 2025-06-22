#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, copy_inhibited)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    auto copy = pdata;                                 // <-- copy initializer inhibited
}
