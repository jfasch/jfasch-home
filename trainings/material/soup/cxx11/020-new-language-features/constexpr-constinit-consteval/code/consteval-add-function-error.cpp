#include <iostream>

consteval int add(int l, int r)
{
    return l+r;
}

int main()
{
    int a=40, b=2;
    int answer = add(a, b);                            // <-- ERROR: is not usable in a constant expression
    std::cout << answer << '\n';
    return 0;
}
