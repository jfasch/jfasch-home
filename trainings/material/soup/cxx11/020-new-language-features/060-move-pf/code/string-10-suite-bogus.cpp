#include <gtest/gtest.h>

#include "string-10.h"

static String make_a_string_from(const char* s)
{
    String ret_s(s);
    return ret_s;                           // <--- copy constructor requested but deleted
}

TEST(string_move_suite, bogus)
{
    String s = make_a_string_from("Hello"); // <--- copy constructor requested but deleted
}
