#include <string>
#include <iostream>

extern std::string other_string;
std::string my_string{"hello " + other_string};

int main()
{
    std::cout << my_string << std::endl;
    return 0;
}
