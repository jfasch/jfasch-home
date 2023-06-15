#include <list>
#include <ranges>
#include <iostream>

void print(const auto& coll)                           // <--- note the const!
{
    for (const auto& elem: coll)
        std::cout << elem << std::endl;
}

int main()
{
    std::list numbers = {2, 1, 4, 3, 5};
    print(numbers | std::views::drop(2));              // <--- compiler error
    return 0;
}
