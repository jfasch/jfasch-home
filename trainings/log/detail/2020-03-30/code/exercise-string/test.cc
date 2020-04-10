#include <mystring.h>

#include <gtest/gtest.h>
#include <string.h>


// require basicn functionality: initialization, holding data
TEST(MyStringFunctionality, Initialization)
{
    MyString s1("hallo");
    MyString s2(s1);
    MyString s3;

    const char* cstr1 = s1.str();
    ASSERT_TRUE(strcmp(cstr1, "hallo") == 0);

    const char* cstr2 = s2.str();
    ASSERT_TRUE(strcmp(cstr2, "hallo") == 0);

    ASSERT_EQ(s1.size(), 5);
    ASSERT_EQ(s2.size(), 5);
    ASSERT_EQ(s3.size(), 0);
}

// copy constructor: he makes a real copy; when I assign to the
// original, the copy does not change.
TEST(MyStringFunctionality, CopyIsCopy)
{
    MyString original("original");
    MyString copy(original);

    original = "blah";
    const char* copystr = copy.str();
    ASSERT_TRUE(strcmp(copystr, "original") == 0);
}

TEST(MyStringFunctionality, RandomCasesAfterLookingAtTheSource_HARHAR)
{
    // group1: hah, the cornercase "default ctor"
    {
        MyString s;
        ASSERT_EQ(s.str()[0], 0);
    }

    // group2: we haven't defined that we plan to create strings
    // longer than 20 :-)
    {
        MyString s("this string is much longer than 20, let's see what valgrind has to say");
    }
}

static void copy_a_string_just_for_fun(const MyString& which_string)
{
    MyString copy(which_string);
    (void)copy; // suppress "unused" warning
}
static void take_str_of_a_string_just_for_fun(const MyString& which_string)
{
    const char* s = which_string.str();
    int size = which_string.size();
    (void)s;  // suppress "unused" warning
    (void)size;
}
// require const-correctnes a bit further. copyctor(), str() and
// size() must be const.
TEST(MyStringFunctionality, ConstCorrectness)
{
    MyString s;
    copy_a_string_just_for_fun(s);
    take_str_of_a_string_just_for_fun(s);
}

// now for the really bad stuff: THE SELF ASSIGNMENT TEST
TEST(MyStringFunctionality, SelfAssignment)
{
    // in C, self assignment is legal (can happen in certain
    // cornercase situations)
    {
        int i = 666;
        i = i;
    }

    // hence one should take care to implement classes accordingly.
    {
        MyString t;
        MyString s("hallo");
        t =   /*rv aus operator=()*/   s = s;
        ASSERT_EQ(s.str()[0], s.str()[0]);
        ASSERT_EQ(t.str()[0], s.str()[0]);
    }
}
