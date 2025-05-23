#include <iostream>


class Base
{
public:
    virtual ~Base()             // <--- Preparing polymorpic usage of derived classes
    {
        std::cout << "Base::~Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    virtual ~Derived()          // <--- "virtual" not strictly necessary, but good style
    {
        std::cout << "Derived::~Derived()" << std::endl;
    }
};

int main()
{
    Base* b = new Derived;      // <--- Base* points to Derived object
    delete b;                   // <--- Polymorphic usage: entering cleanup at Derived::~Derived()

    return 0;
}
