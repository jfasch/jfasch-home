#ifndef PERSON_H
#define PERSON_H

#include "string-30.h"

struct Person
{
    Person(String&& firstname, String&& lastname)
    : firstname(firstname), 
      lastname(lastname) {}

    String firstname;
    String lastname;
};

#endif
