#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, more_condensed_creation)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
}
