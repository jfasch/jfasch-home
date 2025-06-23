#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, refcount_if)
{
    auto pdata = std::make_shared<BigData>(100, 'a');
    auto copy = pdata;
    if (pdata.use_count() == 2)                        // <-- there be dragons!
        /*do something*/;
}
