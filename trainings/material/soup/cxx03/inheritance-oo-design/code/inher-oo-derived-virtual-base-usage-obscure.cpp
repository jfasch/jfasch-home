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
    void method() const       // <--- virtual omitted: correct but less readable
    {
        std::cout << "Derived::method()" << std::endl;
    }
};

int main()
{
    Derived d;
    Base* b = &d;
    b->method();              // <-- correct: calling Derived::method()
    
    return 0;
}
