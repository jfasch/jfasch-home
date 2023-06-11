#include <vector>
#include <ranges>
#include <iostream>

int main()
{
    std::vector numbers = {1, 3, 4, 3, 5, 2};
    auto even = numbers | std::views::filter([](auto elem) { return elem%2==0; });
    for (auto& elem: even)
        elem += 1;
    for (auto elem: even)
        std::cout << elem << std::endl;
    return 0;
}
