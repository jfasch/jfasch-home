#include <stdio.h>

int main(void)
{
    unsigned int i = 0xffffffff;
    i += 1;
    printf("%d\n", i);    /* will print 0!!! */
    return 0;
}
