#include <iostream>

constexpr bool is_even(unsigned num)
{
    return num % 2 == 0;
}

int main()
{
    if constexpr (is_even(6))                          // <-- better
        std::cout << "even\n";
    else
        std::cout << "odd\n";
    return 0;
}
