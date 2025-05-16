#include <vector>
#include <ranges>
#include <iostream>

int main()
{
    std::vector numbers = {2, 1, 4, 3, 5};
    auto even = numbers | std::views::drop(2);
    std::cout << even.size() << std::endl;             // <--- ok: fast
    return 0;
}
