#include <gtest/gtest.h>
#include <cstring>

#include "person-20.h"

TEST(person_suite, bogus)
{
    Person p("Joerg", "Faschingbauer");

    ASSERT_EQ(strcmp(p.firstname.c_str(), "Joerg"), 0);
    ASSERT_EQ(strcmp(p.lastname.c_str(), "Faschingbauer"), 0);
}
