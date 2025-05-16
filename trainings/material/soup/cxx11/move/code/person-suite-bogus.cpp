#include <gtest/gtest.h>
#include <cstring>

#include "person-10.h"

TEST(person_suite, bogus)
{
    Person p("Joerg", "Faschingbauer");  // <--- temporary String object -> move ctor

    ASSERT_EQ(strcmp(p.firstname.c_str(), "Joerg"), 0);
    ASSERT_EQ(strcmp(p.lastname.c_str(), "Faschingbauer"), 0);
}
