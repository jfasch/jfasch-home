#include "userdb.h"
#include <iostream>

int main()
{
    UserDB db;
    User joerg("Joerg", "Faschingbauer", 55);
    db.insert(joerg);
    return 0;
}
