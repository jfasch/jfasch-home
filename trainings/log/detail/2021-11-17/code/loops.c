#include <stdio.h>


int main(void)
{
    int i = 0;
    int s = 0;
    while (i <= 10) {
        s += i;
        i += 1;
    }
    printf("sum (while): %d\n", s);

    s = 0;
    for (i = 0; i <= 10; i++)
        s += i;
    printf("sum (for): %d\n", s);
    
    return 0;
}
