#include <gtest/gtest.h>

TEST(structured_binding_suite, array_const_reference)
{
    int array[] {1, 2, 3};

    const auto& [x, y, z] = array;

    ASSERT_EQ(x, array[0]);
    ASSERT_EQ(y, array[1]);
    ASSERT_EQ(z, array[2]);

    // x, y, z are *const references*, so the compiler won't let me
    // assign ("error: assignment of read-only variable")

    // x = y = z = 666;  <--- does not compile

    // but lets make sure that x, y, z are still *references* (not
    // that the compiler error message says "assignment of read-only
    // **variable**" which is suspicious). lets make sure that we
    // really talk about references:
    ASSERT_EQ(&x, &array[0]);
    ASSERT_EQ(&y, &array[1]);
    ASSERT_EQ(&z, &array[2]);
}
