#include <stdio.h>

int main(void)
{
    int ten_integers[10];
    int i = 0;
    while (1) {
        printf("%d\n", i);
        ten_integers[i] = i;
    }
    return 0;
}
