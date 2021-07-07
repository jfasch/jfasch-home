#include <stdio.h>

int main(void)
{
    int c, i;
    int nwhite = 0, nother = 0;
    int ndigit[10];

    // explicit array initialization
    for (i=0; i<10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;

    // output stats
    for (i=0; i<10; i++)
        printf("#%c: %d\n", '0'+i, ndigit[i]);

    printf("#white: %d\n#other: %d\n", 
           nwhite, nother);
    return 0;
}
