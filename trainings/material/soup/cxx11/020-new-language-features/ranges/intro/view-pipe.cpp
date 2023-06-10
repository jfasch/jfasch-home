#include <vector>
#include <ranges>
#include <iostream>

int main()
{
    std::vector numbers = {2, 1, 4, 3, 5}; 
    auto first_two_dropped = numbers | std::ranges::views::drop(2);

    for (auto i: first_two_dropped)
        std::cout << i << std::endl;

    return 0;
}
