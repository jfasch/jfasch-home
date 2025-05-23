#include <iostream>


class Base
{
public:
    void method() const
    {
        std::cout << "Base::method()" << std::endl;
    }
};

class Derived : public Base
{
public:
    void method() const
    {
        std::cout << "Derived::method()" << std::endl;
    }
};

int main()
{
    Base b;
    b.method();      // <--- calling Base::method()

    Derived d;
    d.method();      // <--- calling Derived::method()
    
    return 0;
}
