#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    constexpr std::vector numbers{2, 1, 3};
    constexpr std::sort(numbers.begin(), numbers.end());

    for (auto n: numbers)
        std::cout << n << std::endl;

    return 0;
}
