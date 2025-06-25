#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, reset_exchange)
{
    auto pdata = std::make_shared<BigData>(100, 'a');
    auto copy = pdata;

    BigData* newdata = new BigData(1000, 'b');
    pdata.reset(newdata);                              // <-- unref original, ref new
    ASSERT_EQ(pdata.get(), newdata);
    ASSERT_EQ(copy.use_count(), 1);
}
