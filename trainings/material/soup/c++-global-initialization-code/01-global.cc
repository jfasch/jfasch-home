#include <string>
#include <iostream>


std::string global_str("global_str");

int main()
{
    std::cout << global_str << std::endl;
    return 0;
}
