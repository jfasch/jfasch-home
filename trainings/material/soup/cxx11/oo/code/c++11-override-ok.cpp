#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base() {}

    virtual void method() const
    {
        cout << "Base::method" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void method() const
    {
        cout << "Derived::method" << endl;
    }
};

int main()
{
    Derived d;
    Base* b = &d;
    b->method();
    return 0;
}
