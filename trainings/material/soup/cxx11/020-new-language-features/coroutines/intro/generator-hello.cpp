#include "generator.h"
#include <iostream>

Generator<std::string> hello()
{
    std::cout << "Saying Hello" << std::endl;
    co_yield "Hello";
    std::cout << "Not Saying Bye" << std::endl;
    co_return;
}

int main()
{
    auto hello_instance = hello();

    for (auto elem: hello_instance)
        std::cout << elem << std::endl;

    return 0;
}
