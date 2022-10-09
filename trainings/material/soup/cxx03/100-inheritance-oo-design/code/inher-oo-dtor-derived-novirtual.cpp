#include <iostream>


class Base
{
public:
    ~Base() 
    {
        std::cout << "Base::~Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "Derived::~Derived()" << std::endl;
    }
};

int main()
{
    Derived d;

    return 0;
}
