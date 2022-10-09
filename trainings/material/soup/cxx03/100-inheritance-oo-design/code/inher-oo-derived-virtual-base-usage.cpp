#include <iostream>


class Base
{
public:
    virtual void method() const
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
    b->method();       // <--- **dynamic dispatch**: calling Derived::method()!
    
    return 0;
}
