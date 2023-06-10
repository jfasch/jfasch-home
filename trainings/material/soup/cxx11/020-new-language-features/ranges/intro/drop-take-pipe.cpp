#include <vector>
#include <ranges>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector numbers = {2, 1, 4, 3, 5}; 

    for (auto i: numbers | std::ranges::views::drop(2) | std::ranges::views::take(2))
        std::cout << i << std::endl;

    return 0;
}
