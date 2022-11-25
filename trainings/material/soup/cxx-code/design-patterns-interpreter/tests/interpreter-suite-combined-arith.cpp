#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, combined_arith)
{
    Literal l7(7);
    Literal l3(3);
    Literal l1(1);

    Addition a_7_plus_3(l7, l3);
    Subtraction s_3_minus_1(l3, l1);

    Multiplication total(a_7_plus_3, s_3_minus_1);

    ASSERT_EQ(total.evaluate(), 20);
}
