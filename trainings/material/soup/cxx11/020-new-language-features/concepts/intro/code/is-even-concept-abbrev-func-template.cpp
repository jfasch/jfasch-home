#include <concepts>
#include <iostream>

bool is_even(std::integral auto num)                   // <--- cool: abbreviated function templates
{                                                      //      (with constraint std::integral)
    return (num % 2) == 0;
}

int main()
{
    is_even(42);
    return 0;
}
