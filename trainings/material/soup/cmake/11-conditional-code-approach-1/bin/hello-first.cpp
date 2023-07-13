#include "greeter-simple.h"
#include "greeter-name.h"

#include <DemoConfig.h>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Version " << DEMO_MAJOR << '.' << DEMO_MINOR << std::endl;

    SimpleGreeter().sayhello();
    if (argc == 2)
        NameGreeter(argv[1]).sayhello();
    return 0;
}
