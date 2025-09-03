#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, reset)
{
    auto pdata = std::make_shared<BigData>(100, 'a');
    auto copy = pdata;                                 // <-- create second reference

    pdata.reset();                                     // <-- drop one reference on original
    ASSERT_EQ(pdata, nullptr);
    ASSERT_EQ(copy.use_count(), 1);

    copy.reset();                                      // <-- drop last reference (deallocated object)
}
