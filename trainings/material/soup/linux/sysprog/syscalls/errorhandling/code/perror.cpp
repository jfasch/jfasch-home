#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("/etc/passwd", O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    return 0;
}
