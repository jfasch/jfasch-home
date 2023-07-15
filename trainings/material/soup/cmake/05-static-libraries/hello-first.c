#include "hello.h"
#include "hello-name.h"

int main(int argc, char** argv)
{
    hello();
    if (argc == 2)
        hello_name(argv[1]);
    return 0;
}
