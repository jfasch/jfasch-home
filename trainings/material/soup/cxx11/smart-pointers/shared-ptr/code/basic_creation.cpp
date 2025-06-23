#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(shared_ptr_suite, basic_creation)
{
    BigData* data = new BigData(100, 'a');
    std::shared_ptr<BigData> pdata(data);
    ASSERT_EQ(pdata.use_count(), 1);                   // <-- pdata is the only reference
}
