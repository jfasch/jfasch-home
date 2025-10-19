#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("/tmp/somefile", O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char bytes[] = "one line of text\n";
    ssize_t nbytes_written = write(fd, bytes, sizeof(bytes));
    if (nbytes_written == -1) {
        perror("write");
        return 1;
    }
    
    close(fd);
    return 0;
}
