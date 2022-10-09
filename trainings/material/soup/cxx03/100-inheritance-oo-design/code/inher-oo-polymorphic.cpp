#include <iostream>


class Base
{
public:
    virtual void method() const
    {
        std::cout << "Base::method()" << std::endl;
    }
};

class Derived1 : public Base
{
public:
    virtual void method() const
    {
        std::cout << "Derived1::method()" << std::endl;
    }
};

class Derived2 : public Base
{
public:
    virtual void method() const
    {
        std::cout << "Derived2::method()" << std::endl;
    }
};


int main()
{
    Base* thermometers[2];

    Derived1 d1;
    Derived2 d2;

    thermometers[0] = &d1;
    thermometers[1] = &d2;

    for (int i=0; i<2; i++)
        thermometers[i]->method();

    return 0;
}
