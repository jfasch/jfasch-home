#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, reset)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    pdata.reset();                                     // <-- deallocate managed object
    ASSERT_EQ(pdata, nullptr);
}
