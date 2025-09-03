#include <iostream>

constexpr int add(int l, int r)
{
    return l+r;
}

constexpr int add3(int v1, int v2, int v3)
{
    return add(v1, add(v2, v3));
}

int main()
{
    const int a=40, b=2, c=624;
    constexpr int answer = add3(a, b, c);
    std::cout << answer << '\n';
    return 0;
}
