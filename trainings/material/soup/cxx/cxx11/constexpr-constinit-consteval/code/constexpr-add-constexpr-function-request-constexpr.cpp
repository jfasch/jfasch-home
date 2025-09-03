#include <iostream>

constexpr int add(int l, int r)
{
    return l+r;
}

int main()
{
    const int a=40, b=2;                               // <-- immutable
    constexpr int answer = add(a, b);                  // <-- force compiletime evaluation
    std::cout << answer << '\n';
    return 0;
}
