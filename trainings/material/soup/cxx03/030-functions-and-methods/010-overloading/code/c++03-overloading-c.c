#include <stdio.h>

void f(int i)
{
    printf("%s\n", __PRETTY_FUNCTION__);
}
void f(char* s)
{
    printf("%s\n", __PRETTY_FUNCTION__);
}
