#include "greeter-name.h"
#include <iostream>

void NameGreeter::sayhello()
{
    std::cout << "Hello " << _name << '\n';
}
