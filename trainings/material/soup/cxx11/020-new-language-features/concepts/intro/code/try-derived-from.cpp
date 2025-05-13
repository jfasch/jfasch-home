#include <concepts>

class Base {};
class Derived1 : public Base {};
class Derived2 : public Base {};

template <typename T>
requires std::derived_from<T, Base>
void foo(const T* obj)
{
    const Base* b = obj;
    (void)b;
}

int main()
{
    Derived1 d;
    foo(&d);
//    foo(42);
    return 0;
}
