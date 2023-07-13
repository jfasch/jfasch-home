#include "greeter-name.h"
#include <iostream>

void NameGreeter::sayhello()
{
#if DEMO_USE_BLACKLIST == 1
    if (_blacklist.is_forbidden(_name))
        std::cout << "Goodbye " << _name << '\n';
#else
    std::cout << "Hello " << _name << '\n';
#endif
}
