#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, subtraction)
{
    Literal lhs(1);
    Expression& e_lhs = lhs;

    Literal rhs(2);
    Expression& e_rhs = rhs;

    Subtraction sub(e_lhs, e_rhs);
    Expression& e_sub = sub;
    
    ASSERT_EQ(e_sub.evaluate(), -1);
}
