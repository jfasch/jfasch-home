#include <display-console.h>

#include <iostream>
#include <cmath>

int main()
{
    ConsoleDisplay display(11, '*', ' ', -1, +1, 0, std::cout);
    double x = 0;
    double step = M_PI/8;
    while (true) {
        display.show_temperature(sin(x += step));
        std::cout << std::endl;
    }
    return 0;
}
