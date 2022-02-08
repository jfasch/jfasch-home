#include "user.h"
#include <iostream>

using namespace std;


int main()
{
    User joerg("Joerg Trittsicher", "Faschingbauer", 55);

    cout << "Firstname: " << joerg.firstname << endl;
    cout << "Lastname: " << joerg.lastname << endl;
    cout << "Age: " << joerg.age << endl;

    return 0;
}
