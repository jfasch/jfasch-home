#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("/tmp/somefile", O_WRONLY|O_APPEND);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char third_line[] = "third line\n";

    ssize_t nbytes_written = write(fd, third_line, sizeof(third_line));
    if (nbytes_written == -1) {
        perror("write");
        return 1;
    }
    
    close(fd);
    return 0;
}
