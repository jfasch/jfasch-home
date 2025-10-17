#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("/etc/passwd", O_RDONLY);
    // ... do something with fd
    close(fd);
    return 0;
}
