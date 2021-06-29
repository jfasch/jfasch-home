#include <string.h>
#include <stdio.h>

int main(void)
{
    char src[] = "abc";
    char dest[2]; // far too less, should be at least 4!

    strcpy(dest, src);
    printf("src: %s, dest: %s\n", src, dest);

    return 0;
}
