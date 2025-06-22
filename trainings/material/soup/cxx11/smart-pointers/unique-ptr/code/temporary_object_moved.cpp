#include "big-data.h"
#include <gtest/gtest.h>
#include <memory>

// --- temporaries? rvalues? move!

// see also: move

// doc: https://en.cppreference.com/w/cpp/memory/unique_ptr/unique_ptr.html move ctor

// * compiler can prove
// * transfers content into function -> move ctor
// * blah

static void foo(std::unique_ptr<BigData> d)            // <-- pass by copy
{
    // ... do domething with p
}

TEST(unique_ptr_suite, temporary_object_moved)
{
    foo(std::make_unique<BigData>(100, 'a'));          // <-- pass by copy
}

