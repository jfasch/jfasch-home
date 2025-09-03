#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(weak_ptr_suite, basic_usage)
{
    auto pdata = std::make_shared<BigData>(100, 'a');
    std::weak_ptr<BigData> maybe(pdata);
    
    // ... time passes ... pdata might unref object ...

    if (std::shared_ptr<BigData> p = maybe.lock(); p) {
        ASSERT_EQ(p.use_count(), 2);
        /*do something with*/p->at(42);
    }
}
