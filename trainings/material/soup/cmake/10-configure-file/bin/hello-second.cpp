#include "greeter-simple.h"
#include "greeter-name.h"

#include <DemoConfig.h>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Ha, here's a second world greeter!\n";
    std::cout << "Version " << DEMO_MAJOR << '.' << DEMO_MINOR << std::endl;

    SimpleGreeter().sayhello();
    
    for (int i=1; i<argc; i++)
        NameGreeter(argv[i]).sayhello();
    return 0;
}
