#include "greeter-simple.h"
#include "greeter-name.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Ha, here's a second world greeter!\n";
    SimpleGreeter().sayhello();
    
    for (int i=1; i<argc; i++)
        NameGreeter(argv[i]).sayhello();
    return 0;
}
