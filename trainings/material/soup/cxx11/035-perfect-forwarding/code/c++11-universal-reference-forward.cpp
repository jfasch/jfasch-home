#include <iostream>
#include <string>

void lo_function(const std::string&)
{
    std::cout << "  lo_function(const std::string&)" << std::endl;
}

void lo_function(std::string&&)
{
    std::cout << "  lo_function(std::string&&)" << std::endl;
}

template <typename T>
void function(T&& t)
{
    lo_function(std::forward<T>(t));
}

int main()
{
    std::cout << "passing lvalue" << std::endl;
    std::string lvalue;
    function(lvalue);

    std::cout << "passing rvalue reference" << std::endl;
    function(std::move(lvalue));
    return 0;
}
