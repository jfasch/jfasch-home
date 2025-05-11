#include <stdlib.h>

[[noreturn]] void terminate()
{
    exit(0);
}

int foo()
{
    terminate();
    return 42;                                         // <-- *could* be warned
}

int main()
{
    return foo();
}
