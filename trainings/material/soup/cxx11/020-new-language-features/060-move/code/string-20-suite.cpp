#include <gtest/gtest.h>

#include "string-20.h"

static String make_a_string_from(const char* s)
{
    String ret_s(s);
    return ret_s;                              // <--- move-return
}

TEST(string_move_suite, move_return)
{
    String s = make_a_string_from("Hello");    // <--- move-initialization
}
