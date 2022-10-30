#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, variable_used_as_expression)
{
    Context context;

    Variable v1(context, "i");
    Literal l(42);
    Assignment ass_v1(v1, l);
    ass_v1.evaluate();             // <--- "i = 42" (not consuming assignment as expression)

    Variable v2(context, "j");
    Assignment ass_v2(v2, v1);
    ass_v2.evaluate();             // <--- "i = j"

    ASSERT_EQ(v2.evaluate(), 42);
}
