#include <vector>
#include <ranges>
#include <iostream>

int main()
{
    std::vector numbers = {2, 1, 4, 3, 5}; 
    auto first_two_dropped = std::views::drop(numbers, 2);
    auto first_two_dropped_next_two_taken = std::views::take(first_two_dropped, 2);

    for (auto i: first_two_dropped_next_two_taken)
        std::cout << i << std::endl;

    return 0;
}
