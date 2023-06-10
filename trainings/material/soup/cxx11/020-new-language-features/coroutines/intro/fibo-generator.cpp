#include "generator.h"
#include <iostream>

Generator<uint64_t> fibonacci()
{
    uint64_t first = 1;
    uint64_t second = 1;

    co_yield first;
    co_yield second;

    while (true) {
        uint64_t third = first + second;

        co_yield third;
        
        first = second;
        second = third;
    }
}

int main()
{
    for (auto num: fibonacci())
        std::cout << num << std::endl;

    return 0;
}
