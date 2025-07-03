#include <vector>
#include <array>
#include <list>
#include <iostream>

void print(const std::vector<int>& numbers)
{
    for (int elem: numbers)
        std::cout << elem << std::endl;
}

void print(const std::array<int, 5>& numbers)
{
    for (int elem: numbers)
        std::cout << elem << std::endl;
}

void print(auto numbers)

int main()
{
    std::vector my_vector = {1,2,3,4,5};
    print(my_vector);

    std::array my_array = {1,2,3,4,5};
    print(my_array);

    return 0;
}
