#include "userdb.h"
#include <iostream>
#include <cassert>

int main()
{
    UserDB db;

    // setup db to have something to search for
    // ----------------------------------------
    db.insert(User("Philipp", "Lichtenberger", 35));
    db.insert(User("Joerg", "Faschingbauer", 55));
    db.insert(User("Caro", "Faschingbauer", 24));

    // test the search
    // ---------------

    // we find the *first* user if it exists
    User found = db.search_by_lastname("Faschingbauer");
    assert(found.firstname() == "Joerg");
    assert(found.lastname() == "Faschingbauer");
    assert(found.age() == 55);

    // lacking knowledge of exception handling, we have to return an
    // invalid user when none exists.
    User notfound = db.search_by_lastname("DoesNotExist");
    assert(!notfound.isvalid());

    return 0;
}
