#include <iostream>

int main()
{
    int i;

    while (true) {
        std::cin >> i;
        if (std::cin.eof())
            break;
        std::cout << i << std::endl;
    }
    
    return 0;
}
