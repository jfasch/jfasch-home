#include <vector>
#include <iostream>

int main()
{
    std::vector<int> ints(3, 42);
    for (int i: ints) std::cout << i << '\n';

    return 0;
}
