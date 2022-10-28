#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, addition)
{
    Literal lhs(1);
    Expression& e_lhs = lhs;

    Literal rhs(2);
    Expression& e_rhs = rhs;

    Addition add(e_lhs, e_rhs);       // <--- adds two *Expression* values (not only Literals)
    Expression& e_add = add;          // <--- Addition *is-a* Expression
    ASSERT_EQ(e_add.evaluate(), 3);   // <--- ... and is evaluated as such
}
