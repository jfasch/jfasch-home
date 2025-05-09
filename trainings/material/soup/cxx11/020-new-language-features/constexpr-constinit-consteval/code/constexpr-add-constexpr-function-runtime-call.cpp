#include <iostream>

constexpr int add(int l, int r)
{
    return l+r;
}

int main()
{
    int a=42, b=2;                                     // <-- mutable
    int answer = add(a, b);                            // <-- *don't* force compiletime evaluation
    std::cout << answer << '\n';
    return 0;
}
