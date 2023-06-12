#include <iostream>

template <typename T>
bool is_even(T num)
{
    return (num % 2) == 0;
}

int main()
{
    std::cout << is_even(3) << std::endl;
    std::cout << is_even(4UL) << std::endl;
    std::cout << is_even(4L) << std::endl;
    return 0;
}
