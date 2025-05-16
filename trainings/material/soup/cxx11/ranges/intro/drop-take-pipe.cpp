#include <vector>
#include <ranges>
#include <iostream>

int main()
{
    std::vector numbers = {2, 1, 4, 3, 5}; 

    for (auto i: numbers | std::views::drop(2) | std::views::take(2))
        std::cout << i << std::endl;

    return 0;
}
