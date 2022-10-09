#include <iostream>


class Base
{
public:
    ~Base() 
    {
        std::cout << "Base::~Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "Derived::~Derived()" << std::endl;
    }
};

int main()
{
    Base* b = new Derived;      // <--- Base* points to Derived object
    delete b;                   // <--- BUG: Derived's destructor not called

    return 0;
}
