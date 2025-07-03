#include <random>
#include <algorithm>
#include <execution>
#include <iostream>

int main()
{
    std::random_device rd;
    std::vector<int> numbers;
    for (int _=0; _<100000; _++)
        numbers.push_back(rd());

    std::sort(std::execution::par, numbers.begin(), numbers.end());
    for (int elem: numbers)
        std::cout << elem << std::endl;
    return 0;
}
