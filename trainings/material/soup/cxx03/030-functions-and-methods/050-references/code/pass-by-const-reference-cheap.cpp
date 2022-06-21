#include <gtest/gtest.h>

struct person
{
    char firstname[128];
    char lastname[128];
};

void pass_by_const_reference_cheap(const person& p)
{
    // ... do something with &p, read-only ...
}

TEST(references_suite, const_reference_cheap)
{
    person p{"Joerg", "Faschingbauer"};
    pass_by_const_reference_cheap(p);   // <--- copying 8 bytes (a pointer) to callee
}
