#include <iostream>


class Base
{
public:
    ~Base() 
    {
        std::cout << "Base::~Base()" << std::endl;
    }
};

int main()
{
    Base b;

    return 0;
}
