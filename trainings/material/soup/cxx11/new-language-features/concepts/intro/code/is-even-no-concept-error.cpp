#include <iostream>

template <typename T>
bool is_even(T num)
{
    return (num % 2) == 0;                             // <-- % on T
}

int main()
{
    is_even(1.5);                                      // <-- requiring % on T=double
    return 0;
}
