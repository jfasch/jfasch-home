#include <gtest/gtest.h>

struct person
{
    char firstname[128];
    char lastname[128];
};

void pass_by_copy_expensive(person p)
{
    // ... do something with p, read-only ...
}

TEST(references_suite, copy_expensive)
{
    person p{"Joerg", "Faschingbauer"};
    pass_by_copy_expensive(p);   // <--- copying 256 bytes to callee
}
