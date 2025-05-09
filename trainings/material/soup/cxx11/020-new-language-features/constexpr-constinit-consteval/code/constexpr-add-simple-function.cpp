#include <iostream>

int add(int l, int r)
{
    return l+r;
}

int main()
{
    const int a=40, b=2;                               // <-- immutable!
    int answer = add(a, b);
    std::cout << answer << '\n';
    return 0;
}
