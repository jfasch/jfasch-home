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
    void method() const override
    {
        std::cout << "Derived::method()" << std::endl;
    }
};

int main()
{
    Derived d;
    d.method();
    Base* b = &d;
    b->method();

    return 0;
}
