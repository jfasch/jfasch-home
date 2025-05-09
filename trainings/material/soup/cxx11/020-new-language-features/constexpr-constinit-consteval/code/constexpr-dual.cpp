#include <iostream>

constexpr int multiply(int a, int b)
{
    return a*b;
}

int main()
{
    int a = 10, b=20;
    int c = multiply(a, b);
    std::cout << c << '\n';
    return 0;
}
