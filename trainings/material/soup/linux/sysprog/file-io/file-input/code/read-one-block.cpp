#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("/etc/passwd", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    char bytes[16];
    ssize_t nbytes_read = read(fd, bytes, 16);         // <-- at most 16 into bytes[]
    if (nbytes_read == -1) {
        perror("read");
        return 1;
    }

    ssize_t nbytes_written = write(STDOUT_FILENO,      // <-- just to see them somewhere
                                   bytes, nbytes_read);
    if (nbytes_written == -1) {
        perror("write");
        return 1;
    }
    
    close(fd);
    return 0;
}
