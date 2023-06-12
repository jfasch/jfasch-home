#include <iostream>

template <typename T>
bool is_even(T num)
{
    return (num % 2) == 0;
}

int main()
{
    std::cout << is_even(1.5) << std::endl;
    return 0;
}
