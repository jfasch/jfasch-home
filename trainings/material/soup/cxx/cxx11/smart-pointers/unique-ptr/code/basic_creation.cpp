#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

TEST(unique_ptr_suite, basic_creation)
{
    BigData* data = new BigData(100, 'a');
    std::unique_ptr<BigData> pdata(data);
}
