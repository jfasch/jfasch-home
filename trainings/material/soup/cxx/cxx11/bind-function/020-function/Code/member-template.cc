#include <iostream>

struct X
{
    template <typename T> void f(T a)
    {
        std::cout << a << std::endl;
    }
};

int main()
{
    X x;
    x.f(1);
    x.f("abc");
    return 0;
}
