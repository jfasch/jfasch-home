#include "user.h"
#include "userdb.h"

#include <iostream>

using namespace std;


int main()
{
    struct User joerg;
    struct User caro;
    user_init(&joerg, "Joerg", "Faschingbauer", 55);
    user_init(&caro, "Carolin", "Faschingbauer", 24);

    struct UserDB userdb;
    userdb_init(&userdb);

    userdb_insert(&userdb, &joerg);
    userdb_insert(&userdb, &caro);
    // userdb.insert(caro);  <-- I WANT THIS!!

    // userdb_dump(&userdb);
    struct User* found = userdb_search_by_lastname(&userdb, "xxx");

    if (found == NULL)
        cout << "nix gefunden" << endl;
    else
        cout << found->firstname << ' ' << found->lastname << endl;

    return 0;
}
