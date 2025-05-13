#include <concepts>
#include <iostream>

template <typename T>
bool is_even(T num) requires std::integral<T>          // <--- same, but different
{
    return (num % 2) == 0;
}

int main()
{
    is_even(42);
    return 0;
}
