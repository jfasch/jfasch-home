#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, variable_not_set)
{
    Context context;              // <--- e.g. local or global scope (if we had functions)
    Variable v(context, "i");     // <--- v lives in context, under the name "i"
    ASSERT_EQ(v.evaluate(), 0);   // <--- v has never been assigned to -> default value 0
}
