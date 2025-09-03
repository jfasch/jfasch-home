#include <stdio.h>

extern int global;               // <--- "extern" declaration

int main(void)
{
    printf("%d\n", global);
    return 0;
}
