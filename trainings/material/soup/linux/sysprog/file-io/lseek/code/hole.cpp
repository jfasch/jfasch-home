#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <print>

int main()
{
    int fd = open("/tmp/somefile", O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    off64_t pos = lseek64(fd, 10000, SEEK_SET);        // <-- absolute position 10000
    if (pos == -1) {
        perror("lseek");
        return 1;
    }

    char byte = 'X';
    ssize_t nwritten = write(fd, &byte, 1);            // <-- drop byte at 10000
    if (nwritten == -1) {
        perror("write");
        return 1;
    }

    return 0;                                          // <-- fd automatically closed at exit
}
