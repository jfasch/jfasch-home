#ifndef USERDB_H
#define USERDB_H

#include "user.h"


struct UserDB
{
    struct User users[10];
    unsigned int n_users;
};

void userdb_init(struct UserDB* userdb);
void userdb_insert(struct UserDB* userdb, struct User*);
void userdb_dump(struct UserDB* userdb);
struct User* userdb_search_by_lastname(struct UserDB*, char lastname[]);

#endif
