#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, raw_pointer_get)
{
    auto pdata = std::make_shared<BigData>(100, 'a');
    BigData* raw = pdata.get();
    ASSERT_EQ(raw->at(42), 'a');                       // <-- operator->()
    ASSERT_EQ((*raw).at(42), 'a');                     // <-- operator*()
    ASSERT_EQ(raw, pdata.get());                       // <-- .get() leaves pdata untouched
}

