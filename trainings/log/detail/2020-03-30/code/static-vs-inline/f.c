#include "f.h"

#include <stdio.h>


static void g(int i)
{
    h();
    printf("hallo g(%d)\n", i);
}

void f()
{
    printf("hallo f()\n");
    g(666);
}
