#include <stdio.h>

int main(void)
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr+20)
        printf("%6d\t%6.2f\n", fahr, 5.0/9 * (fahr - 32));

    return 0;
}
