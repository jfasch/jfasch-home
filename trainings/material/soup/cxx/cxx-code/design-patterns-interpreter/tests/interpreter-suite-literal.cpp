#include <gtest/gtest.h>

#include <expression.h>


TEST(interpreter_suite, literal)
{
    Literal le(42);
    Expression* e = &le;            // <--- Literal *is-a* Expression
    ASSERT_EQ(e->evaluate(), 42);   // <--- ... and is evaluated as such
}
