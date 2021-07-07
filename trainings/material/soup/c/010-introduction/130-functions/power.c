#include <stdio.h>

int power(int base, int n)
{
    int p = 1;
    while (n--)
        p *= base;
    return p;
}

void main(void)
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("2^%d = %d\n", i, power(2, i));
}
