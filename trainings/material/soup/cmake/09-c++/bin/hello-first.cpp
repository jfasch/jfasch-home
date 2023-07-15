#include "greeter-simple.h"
#include "greeter-name.h"

int main(int argc, char** argv)
{
    SimpleGreeter().sayhello();
    if (argc == 2)
        NameGreeter(argv[1]).sayhello();
    return 0;
}
