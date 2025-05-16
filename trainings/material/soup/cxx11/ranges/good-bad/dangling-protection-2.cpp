#include <vector>
#include <algorithm>                                   // <--- adds to std::ranges namespace
#include <iostream>

int main()
{
    auto numbers = {42, 666, -1, 5};
    auto iter = std::ranges::min_element(numbers);     // <--- numbers satisfies the 
                                                       //      std::ranges::forward_range concept
    std::cout << *iter << std::endl;
    return 0;
}
