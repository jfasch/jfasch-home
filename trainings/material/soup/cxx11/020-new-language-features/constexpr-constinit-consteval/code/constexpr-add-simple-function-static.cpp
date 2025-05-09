#include <iostream>

static int add(int l, int r)                           // <-- only visible inside this compilation unit
{
    return l+r;
}

int main()
{
    const int a=40, b=2;
    int answer = add(a, b);
    std::cout << answer << '\n';
    return 0;
}
