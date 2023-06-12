#include <concepts>
#include <iostream>

/*
template <typename T>
requires std::integral<T>
bool is_even(T num)
{
    return (num % 2) == 0;
}
*/

/*
template <typename T>
bool is_even(T num) requires std::integral<T>          // <--- same, but different
{
    return (num % 2) == 0;
}
*/

/*
template <std::integral T>                             // <--- cool
bool is_even(T num)
{
    return (num % 2) == 0;
}
*/

bool is_even(std::integral auto num)                   // <--- cool: abbreviated function templates
{                                                      //      (with constraint std::integral)
    return (num % 2) == 0;
}

int main()
{
    std::cout << is_even(1.5) << std::endl;
    return 0;
}
