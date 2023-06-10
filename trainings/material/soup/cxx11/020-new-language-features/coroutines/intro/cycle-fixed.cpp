#include "generator.h"
#include <iostream>
#include <vector>

Generator<int> cycle(const std::vector<int> elems)     // <--- BY COPY!!
{
    while (true)
        for (const auto& e: elems)
            co_yield e;
}

int main()
{
    auto c = cycle({1,2,3,4});

    for (auto elem: c)
        std::cout << elem << std::endl;

    return 0;
}
