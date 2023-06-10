#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    auto iter = std::ranges::min_element(
        std::vector{42, 666, -1, 5});                  // <--- temporary used!
    std::cout << *iter << std::endl;

    return 0;
}
