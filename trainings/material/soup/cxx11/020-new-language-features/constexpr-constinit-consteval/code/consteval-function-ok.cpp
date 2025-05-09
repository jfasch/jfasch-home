#include <iostream>

consteval int multiply(int l, int r)
{
    return l*r;
}

int main()
{
    const int a=10, b=20;
    int result = multiply(a, b);
    std::cout << result << '\n';
    return 0;
}
