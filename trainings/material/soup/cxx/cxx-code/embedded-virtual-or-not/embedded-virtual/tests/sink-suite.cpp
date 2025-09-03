#include <sink-copyable.h>
#include <sink-movable.h>

#include <gtest/gtest.h>


TEST(sink_suite, copyable)
{
    {
        SinkCopyable orig("blah");
        ASSERT_EQ(orig.resource(), "blah");
        SinkCopyable copy = orig;
        ASSERT_EQ(orig.resource(), "blah");
        ASSERT_EQ(copy.resource(), "blah");
    }

    {
        SinkCopyable orig("blah");
        SinkCopyable copy("blech");
        copy = orig;
        ASSERT_EQ(orig.resource(), "blah");
        ASSERT_EQ(copy.resource(), "blah");
    }
}

TEST(sink_suite, movable)
{
    {
        SinkMovable orig("blah");
        ASSERT_STREQ(orig.resource(), "blah");
        SinkMovable moved = std::move(orig);
        ASSERT_STREQ(moved.resource(), "blah");
        ASSERT_EQ(orig.resource(), nullptr);
    }
    {
        SinkMovable orig("blah");
        SinkMovable moved("blech");
        moved = std::move(orig);
        ASSERT_STREQ(moved.resource(), "blah");
        ASSERT_EQ(orig.resource(), nullptr);
    }

    // SinkMovable impossible = orig;   // must not compile (copy initializer)

}

