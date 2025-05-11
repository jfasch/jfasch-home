#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(nullptr));
    int number = std::rand();

    bool seen_zero = false;
    
    switch (number) {
        case 0:
            seen_zero = true;                          // <-- warning: this statement may fall through
        case 1:
            std::cout << "uh, this was unlikely\n";
            break;
    }

    if (seen_zero)
        std::cout << "uh, this was even more unlikely\n";

    return 0;
}
