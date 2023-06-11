#include <vector>
#include <iostream>

template <typename R>                                  // <--- good ol'
void print(const R& range)                             //      function template
{
    for (const auto& elem: range)
        std::cout << elem << std::endl;
}

int main()
{
    std::vector numbers = { 1,2,3,4,5 };
    print(numbers);
    return 0;
}
