#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, raw_pointer_release)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    BigData* raw = pdata.release();                    // <-- developer is now responsible for `raw`
    ASSERT_EQ(pdata, nullptr);
    ASSERT_EQ(raw->at(42), 'a');
    delete raw;                                        // <-- (here)
}

