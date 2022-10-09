#include <iostream>


class Base
{
public:
    void method() const
    {
        std::cout << "Base::method()" << std::endl;
    }
};

int main()
{
    Base b;
    b.method();      // <--- calling Base::method() (obviously)

    return 0;
}
