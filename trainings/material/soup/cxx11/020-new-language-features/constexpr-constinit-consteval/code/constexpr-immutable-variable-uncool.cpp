#include <iostream>

constexpr int add(int l, int r)
{
    return l+r;
}

int main()
{
    const int a=40, b=1;
    constexpr int answer = add(a, b);
    ++answer;                                          // error: increment of read-only variable ‘answer’
    std::cout << answer << '\n';
    return 0;
}
