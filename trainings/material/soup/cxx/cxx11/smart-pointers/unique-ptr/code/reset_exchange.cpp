#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, reset_exchange)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    BigData* newdata = new BigData(1000, 'b');
    pdata.reset(newdata);                              // <-- deallocate, and point to new object
    ASSERT_EQ(pdata.get(), newdata);
}
