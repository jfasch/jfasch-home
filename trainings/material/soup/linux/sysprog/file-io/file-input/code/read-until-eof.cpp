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

    while (true) {
        char bytes[16];
        ssize_t nbytes_read = read(fd, bytes, 16);
        if (nbytes_read == -1) {
            perror("read");
            return 1;
        }
        if (nbytes_read == 0)                          // <-- end-of-file
            break;

        ssize_t nbytes_written = write(STDOUT_FILENO, bytes, nbytes_read);
        if (nbytes_written == -1) {
            perror("write");
            return 1;
        }
    }
    
    close(fd);
    return 0;
}
