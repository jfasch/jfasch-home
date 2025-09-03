#include <iostream>


class Base
{
public:
    virtual ~Base() = 0;
};

class Derived : public Base
{
public:
    virtual ~Derived() 
    {
    }
};

int main()
{
    Derived d;

    return 0;
}
