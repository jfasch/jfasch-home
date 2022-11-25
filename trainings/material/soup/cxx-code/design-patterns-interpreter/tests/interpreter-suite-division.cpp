#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, division)
{
    Literal lhs(3);
    Expression& e_lhs = lhs;

    Literal rhs(2);
    Expression& e_rhs = rhs;

    Division div(e_lhs, e_rhs);
    Expression& e_div = div;
    
    ASSERT_EQ(e_div.evaluate(), 1);
}
