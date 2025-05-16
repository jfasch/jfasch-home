#include <vector>
#include <ranges>
#include <iostream>

void print(const auto& coll)
{
    for (const auto& elem: coll)
        std::cout << elem << std::endl;
}

int main()
{
    std::vector numbers = {2, 1, 4, 3, 5}; 
    print(numbers | std::views::drop(2));
    return 0;
}
