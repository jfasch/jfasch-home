#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, raw_pointer_get)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    BigData* raw = pdata.get();
    ASSERT_EQ(raw->at(42), 'a');                       // <-- operator->()
    ASSERT_EQ((*raw).at(42), 'a');                     // <-- operator*()
    ASSERT_EQ(raw, pdata.get());                       // <-- .get() leaves pdata untouched
}

