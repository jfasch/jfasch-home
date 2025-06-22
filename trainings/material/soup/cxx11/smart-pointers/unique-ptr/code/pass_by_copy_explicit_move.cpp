#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

static void foo(std::unique_ptr<BigData> d)            // <-- pass by copy
{
    // ... do domething with p
}

TEST(unique_ptr_suite, pass_by_copy_explicit_move)
{
    auto pdata = std::make_unique<BigData>(100, 'a');
    foo(std::move(pdata));                             // <-- explicit ownership transfer
    ASSERT_EQ(pdata, nullptr);                         // <-- pdata **INVALID** after move
}

