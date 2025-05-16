#ifndef PERSON_H
#define PERSON_H

#include "string-30.h"

struct Person
{
    Person(String&& firstname, String&& lastname)   // <--- parameters have names -> lvalues
    : firstname(std::move /*!!*/ (firstname)),      // <--- request String's move contructor
      lastname(std::move /*!!*/ (lastname)) {}

    String firstname;
    String lastname;
};

#endif
