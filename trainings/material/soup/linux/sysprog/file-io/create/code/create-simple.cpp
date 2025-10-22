#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("/tmp/somefile", O_WRONLY | O_CREAT, 
                  0666);                               // <-- note "mode"!
    if (fd == -1) {
        perror("open");
        return 1;
    }
    // ... do something with fd ...
    close(fd);
    return 0;
}
