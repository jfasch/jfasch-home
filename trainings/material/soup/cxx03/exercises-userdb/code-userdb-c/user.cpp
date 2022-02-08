#include "user.h"
#include <cstring>   // string.h
#include <cassert>   // assert.h
#include <iostream>

using namespace std;


void user_init(struct User* user, char firstname[], char lastname[], unsigned int age)
{
    assert(strlen(firstname) < USERNAMELEN);
    assert(strlen(lastname) < USERNAMELEN);

    strcpy(user->firstname, firstname);
    strcpy(user->lastname, lastname);
    user->age = age;
}

