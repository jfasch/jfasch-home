#ifndef USER_H
#define USER_H

#define USERNAMELEN 15

struct User
{
    unsigned int age;
    char firstname[USERNAMELEN];  // string
    char lastname[USERNAMELEN];   // string
};

void user_init(struct User* user, char firstname[], char lastname[], unsigned int age);

#endif
