#include <iostream>

constexpr int add(int l, int r)
{
    return l+r;
}

consteval int add3(int v1, int v2, int v3)
{
    return add(v1, add(v2, v3));
}

int main()
{
    const int a=40, b=2;
    int answer = add(a, b);
    std::cout << answer << '\n';
    return 0;
}
