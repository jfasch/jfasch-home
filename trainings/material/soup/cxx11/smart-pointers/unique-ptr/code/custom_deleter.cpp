#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, deleter)
{
    bool deleted = false;
    auto deleter = [&deleted](BigData* obj) {
        deleted = true;
        delete obj;
    };

    std::unique_ptr<BigData, decltype(deleter)> pdata(new BigData(100, 'a'), deleter);
    pdata.reset();
    ASSERT_TRUE(deleted);
}
