#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, multiplication)
{
    Literal lhs(2);
    Expression& e_lhs = lhs;

    Literal rhs(3);
    Expression& e_rhs = rhs;

    Multiplication mul(e_lhs, e_rhs);
    Expression& e_mul = mul;
    
    ASSERT_EQ(e_mul.evaluate(), 6);
}
