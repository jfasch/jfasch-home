#include <iostream>

class Base
{
public:
    void method() const
    {
        std::cout << "Base::method()\n";
    }
};

class Derived : public Base
{
public:
    void method() const
    {
        std::cout << "Derived::method()\n";
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
