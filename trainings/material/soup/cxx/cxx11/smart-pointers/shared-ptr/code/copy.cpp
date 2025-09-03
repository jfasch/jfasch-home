#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, copy)
{
    auto pdata = std::make_shared<BigData>(100, 'a');
    auto copy = pdata;
    ASSERT_EQ(pdata.get(), copy.get());                // <-- both point to same object
    ASSERT_EQ(pdata.use_count(), 2);                   // <-- pointed-to object has one more reference
}
