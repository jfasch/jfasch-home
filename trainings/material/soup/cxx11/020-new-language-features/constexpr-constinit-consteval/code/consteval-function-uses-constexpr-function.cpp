#include <iostream>

constexpr int multiply(int l, int r)
{
    return l*r;
}

consteval int square(int num)
{
    return multiply(num, num);
}

int main()
{
    const int n = 7;
    int result = square(n);
    std::cout << result << '\n';
    return 0;
}
