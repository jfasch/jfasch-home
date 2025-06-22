#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

static void foo(std::unique_ptr<BigData> d)
{
    // ... do something with p
}

TEST(unique_ptr_suite, temporary_object_moved)
{
    foo(std::make_unique<BigData>(100, 'a'));          // <-- std::unique_ptr move ctor called
}
