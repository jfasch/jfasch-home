#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, is_a_pointer)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    ASSERT_EQ(pdata->at(42), 'a');
    ASSERT_EQ((*pdata).at(42), 'a');
}
