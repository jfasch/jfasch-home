#include <concepts>
#include <iostream>

template <typename T>
requires std::integral<T>                              // <-- "cacnonical" syntax
bool is_even(T num)
{
    return (num % 2) == 0;
}

int main()
{
    is_even(1.5);
    return 0;
}
