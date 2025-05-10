#include <iostream>
#include <array>

std::array numbers = {3, 1, 2, 4, 7, 100};

int main()
{
    for (auto size=numbers.size(); int n: numbers) {
        std::cout << n;
        if (--size > 0)
            std::cout << ',';
        else
            std::cout << '\n';
    }
    return 0;
}
