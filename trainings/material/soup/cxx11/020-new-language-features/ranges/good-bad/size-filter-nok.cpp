#include <vector>
#include <ranges>
#include <iostream>

int main()
{
    std::vector numbers = {2, 1, 4, 3, 5};
    auto even = numbers | std::views::filter([](auto elem) { return elem%2==0; });
    std::cout << even.size() << std::endl;             // <--- compiler error: no size()
    return 0;
}
