#include "user.h"
#include <iostream>

using namespace std;


int main()
{
    cout << sizeof(struct User) << endl;

    struct User joerg;
    user_init(&joerg, "J.Trittsicher", "Faschingbauer", 55);

    cout << "Firstname: " << joerg.firstname << endl;
    cout << "Lastname: " << joerg.lastname << endl;
    cout << "Age: " << joerg.age << endl;

    return 0;
}
