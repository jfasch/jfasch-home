#include <iostream>

constexpr int add(int l, int r)
{
    return l+r;
}

constexpr int sum(int num)
{
    if (num == 1)
        return num;
    else
        return add(sum(num-1), num);
}

int main()
{
    const int n = 3;
    constexpr int answer = sum(n);
    std::cout << answer << '\n';
    return 0;
}
