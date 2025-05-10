#include <iostream>

consteval int add(int l, int r)
{
    return l+r;
}

int main()
{
    const int a=40, b=2;
    int answer = add(a, b);                            // <-- no need to force
    std::cout << answer << '\n';
    return 0;
}
