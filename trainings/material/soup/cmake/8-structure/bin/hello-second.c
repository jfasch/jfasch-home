#include "hello.h"
#include "hello-name.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    printf("Ha, here's a second world greeter!\n");
    hello();
    
    for (int i=1; i<argc; i++)
        hello_name(argv[i]);
    return 0;
}
