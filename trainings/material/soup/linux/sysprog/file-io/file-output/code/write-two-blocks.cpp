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

    char first_line[] = "a fresh line of text\n";
    char second_line[] = "second line\n";

    ssize_t nbytes_written = write(fd, first_line, sizeof(first_line));
    if (nbytes_written == -1) {
        perror("first write");
        return 1;
    }
    nbytes_written = write(fd, second_line, sizeof(second_line));
    if (nbytes_written == -1) {
        perror("second write");
        return 1;
    }
    
    close(fd);
    return 0;
}
