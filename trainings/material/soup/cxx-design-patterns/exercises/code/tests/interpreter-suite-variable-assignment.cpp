#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, variable_assignment)
{
    Context context;

    Variable v(context, "i");
    Literal l(42);
    Assignment ass(v, l);               // <--- Assignment object created (but not yet evaluated)

    ASSERT_EQ(ass.evaluate(), 42);      // <--- Assignment evaluation: "i = 42" has value 42 (as in C)
    ASSERT_EQ(context.get("i"), 42);    // <--- variable has made it into context
    ASSERT_EQ(v.evaluate(), 42);        // <--- variable now has a defined value
}
