#include "userdb.h"
#include "user.h"
#include <iostream>
#include <cstring>


using namespace std;


void userdb_init(struct UserDB* userdb)
{
    userdb->n_users = 0;
}

void userdb_insert(struct UserDB* userdb, struct User* user)
{
    if (userdb->n_users == 10) {
        cerr << "userdb_insert: no more space available" << endl;
        return;
    }

    cout << "userdb_insert(" << user->firstname << ' ' << user->lastname << ')' << endl;

    userdb->users[userdb->n_users] = *user;
    userdb->n_users++;
}

void userdb_dump(struct UserDB* userdb)
{
    int i;
    for (i = 0; i < userdb->n_users; i++) {
        cout << "Firstname: " << userdb->users[i].firstname << endl;
        cout << "Lastname: " << userdb->users[i].lastname << endl;
    }
}

struct User* userdb_search_by_lastname(struct UserDB* userdb, char lastname[])
{
    for (int i=0; i<userdb->n_users; i++) {
        if (strcmp(userdb->users[i].lastname, lastname) == 0)
            return &userdb->users[i];
    }

    return NULL;
}
