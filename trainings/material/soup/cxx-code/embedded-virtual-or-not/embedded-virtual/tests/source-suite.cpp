#include <source-copyable.h>
#include <source-movable.h>

#include <gtest/gtest.h>


TEST(source_suite, copyable)
{
    {
        SourceCopyable orig("blah");
        ASSERT_STREQ(orig.get(), "blah");
        ASSERT_EQ(orig.resource(), "blah");
        SourceCopyable copy = orig;
        ASSERT_STREQ(copy.get(), "blah");
        ASSERT_EQ(orig.resource(), "blah");
        ASSERT_EQ(copy.resource(), "blah");
    }

    {
        SourceCopyable orig("blah");
        SourceCopyable copy("blech");
        copy = orig;
        ASSERT_STREQ(copy.get(), "blah");
        ASSERT_EQ(orig.resource(), "blah");
        ASSERT_EQ(copy.resource(), "blah");
    }
}

TEST(source_suite, movable)
{
    {
        SourceMovable orig("blah");
        ASSERT_STREQ(orig.resource(), "blah");
        SourceMovable moved = std::move(orig);
        ASSERT_STREQ(moved.resource(), "blah");
        ASSERT_EQ(orig.resource(), nullptr);
    }
    {
        SourceMovable orig("blah");
        SourceMovable moved("blech");
        moved = std::move(orig);
        ASSERT_STREQ(moved.resource(), "blah");
        ASSERT_EQ(orig.resource(), nullptr);
    }

    // SourceMovable impossible = orig;   // must not compile (copy initializer)
}

