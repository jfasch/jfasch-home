#include <vector>
#include <algorithm>                                   // <--- adds to std::ranges namespace
#include <iostream>

int main()
{
    auto numbers = {42, 666, -1, 5};
    auto iter = std::ranges::min_element(numbers.begin(), numbers.end());
    std::cout << *iter << std::endl;

    return 0;
}
