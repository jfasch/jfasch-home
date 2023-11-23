#include <vector>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"

int main()
{
    std::vector<int> my_vector = { 1,2,3 };
    std::cout << my_vector[3] << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
