#include <gtest/gtest.h>

#include "string-30.h"

static String make_a_string_from(const char* s)
{
    String ret_s(s);
    return ret_s;
}

TEST(string_move_suite, move_assignment)
{
    String s;
    s = make_a_string_from("Hello");   // <--- move assignment
                                       // (assignment from an rvalue)
}
