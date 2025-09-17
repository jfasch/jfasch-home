#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    const char* filename = argv[1];
    int fd;
    char buffer[128];
    ssize_t nread, nwritten;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    while (1) {
        nread = read(fd, buffer, sizeof(buffer));
        if (nread == -1) {
            perror("read");
            return 2;
        }

        // end of file (EOF) reached?
        if (nread == 0)
            break;

        nwritten = write(STDOUT_FILENO, buffer, nread);
        if (nwritten == -1) {
            perror("write");
            return 3;
        }
    }

    close(fd);
    return 0;
}
