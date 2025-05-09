#include <array>
#include <iostream>

const int size = 7;
const std::array<int, size> the_array{2,3,4,5,6,7,8};

int main()
{
    std::cout << the_array.size() << '\n';
    return 0;
}
