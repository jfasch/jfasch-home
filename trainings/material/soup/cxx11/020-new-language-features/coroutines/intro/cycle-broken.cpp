#include "generator.h"
#include <iostream>
#include <vector>

Generator<int> cycle(const std::vector<int>& elems)
{
    while (true)
        for (const auto& e: elems)                     // <--- BOOM!!
            co_yield e;
}

int main()
{
    auto c = cycle({1,2,3,4});                         // <--- temporary
                                                       // <--- temporary gone here
    for (auto elem: c)                                 // <--- c still has reference to it
        std::cout << elem << std::endl;

    return 0;
}
