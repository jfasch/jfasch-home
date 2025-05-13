#include <concepts>
#include <iostream>


template <std::integral T>                             // <--- cool (typename is soo boring)
bool is_even(T num)
{
    return (num % 2) == 0;
}

int main()
{
    is_even(42);
    return 0;
}
