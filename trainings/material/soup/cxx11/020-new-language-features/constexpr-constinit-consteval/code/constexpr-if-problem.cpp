#include <iostream>

constexpr bool is_even(unsigned num)
{
    return num % 2 == 0;
}

int main()
{
    constexpr bool even = is_even(6);                  // <-- workaround
    if (even)                                          // <-- intelligent compiler not guaranteed
        std::cout << "even\n";
    else
        std::cout << "odd\n";
    return 0;
}
