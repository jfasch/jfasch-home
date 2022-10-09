#include <iostream>


class Base
{
public:
    void method() const       // <--- ERROR: virtual omitted -> **no dynamic dispatch**
    {
        std::cout << "Base::method()" << std::endl;
    }
};

class Derived : public Base
{
public:
    virtual void method() const
    {
        std::cout << "Derived::method()" << std::endl;
    }
};

int main()
{
    Derived d;
    Base* b = &d;
    b->method();              // <-- WRONG: calling Base::method()!
    
    return 0;
}
