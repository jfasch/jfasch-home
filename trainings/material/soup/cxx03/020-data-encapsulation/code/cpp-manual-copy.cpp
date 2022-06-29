#include <gtest/gtest.h>
#include <string>

class Copyable
{
public:
    Copyable() = default;  // <--- not auto-generated because other ctors are user defined

    Copyable(const std::string& content)
    : content(content) {}

    Copyable(const Copyable& other)            // <--- copy constructor
    : content(other.content + " (copy)") {}

    Copyable& operator=(const Copyable& other) // <--- assignment operator
    {
        content = other.content + " (assignment)";
        return *this;
    }

    std::string content;
};

TEST(manual_copy_suite, copy_ctor)
{
    Copyable original("some object");
    Copyable copy = original;    // <--- copy constructor

    ASSERT_EQ(original.content, "some object");
    ASSERT_EQ(copy.content, "some object (copy)");
}

TEST(manual_copy_suite, assignment_operator)
{
    Copyable original("some object");
    Copyable copy;
    copy = original;             // <--- assignment operator

    ASSERT_EQ(original.content, "some object");
    ASSERT_EQ(copy.content, "some object (assignment)");
}
