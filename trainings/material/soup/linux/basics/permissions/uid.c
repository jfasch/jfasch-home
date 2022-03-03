#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>


int main(void)
{ 
    printf("%d\n", getuid());
    printf("%d\n", geteuid());
    return 0;
}
