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
    Derived d;
    Base* b = &d;     // <--- **is-a**: Derived is converted to Base, **without** a cast
    b->method();      // <--- **Question**: Base::method() or Derived::method()?
    
    return 0;
}
