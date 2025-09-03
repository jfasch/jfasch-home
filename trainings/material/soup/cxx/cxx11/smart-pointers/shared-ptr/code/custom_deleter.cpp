#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, deleter)
{
    bool deleted1 = false;
    auto deleter1 = [&deleted1](BigData* obj) {
        deleted1 = true;
        delete obj;
    };
    std::shared_ptr<BigData> pdata(new BigData(100, 'a'), deleter1); // <-- ctor parameter

    bool deleted2 = false;
    auto deleter2 = [&deleted2](BigData* obj) {
        deleted2 = true;
        delete obj;
    };
    BigData* newdata = new BigData(100, 'b');

    pdata.reset(newdata, deleter2);                    // <-- unref (and delete) original, ref new
    ASSERT_TRUE(deleted1);

    pdata.reset();                                     // <-- unref (and delete) new data
    ASSERT_TRUE(deleted2);
}
