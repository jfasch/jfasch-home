#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("/tmp/somefile", 
                  O_CREAT | O_EXCL,                      // <-- here!
                  0600);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    // ... do something with fd ...
    close(fd);
    return 0;
}
