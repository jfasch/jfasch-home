#include "base-derived-wo-virtual.h"

#include <iostream>

int main()
{
    {
        Base b;
        std::cout << b.method() << std::endl;
    }
    {
        Derived d;
        std::cout << d.method() << std::endl;
    }
    {
        Derived d;
        Base* b = &d;
        std::cout << b->method() << std::endl;
    }
    return 0;
}
