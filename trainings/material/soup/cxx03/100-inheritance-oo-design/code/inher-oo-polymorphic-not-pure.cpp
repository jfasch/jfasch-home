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

class Derived3 : public Base          // <--- BUG: not implementing method()
{
};


int main()
{
    Base* thermometers[3];

    Derived1 d1;
    Derived2 d2;
    Derived3 d3;                      // <--- BUG: instantiating incomplete type

    thermometers[0] = &d1;
    thermometers[1] = &d2;
    thermometers[2] = &d3;            // <--- BUG: using incomplete type

    for (int i=0; i<3; i++)
        thermometers[i]->method();

    return 0;
}
