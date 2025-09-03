#include <random>
#include <algorithm>
#include <execution>
#include <iostream>

int main()
{
    std::vector<int> numbers;
    for (int i=0; i<1000; i++)
        numbers.push_back(i);

    std::for_each(
        std::execution::par_unseq, 
        numbers.begin(), numbers.end(), 
        [](int elem){ std::cout << elem << std::endl; });

    return 0;
}
