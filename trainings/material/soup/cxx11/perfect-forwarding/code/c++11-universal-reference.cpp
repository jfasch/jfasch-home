#include <iostream>

template<typename T>
void function(T&& t)
{
    std::cout << "  accepted" << std::endl;
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
