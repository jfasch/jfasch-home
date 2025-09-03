#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, more_condensed_creation)
{
    auto pdata = std::make_shared<BigData>(100, 'a');
}
