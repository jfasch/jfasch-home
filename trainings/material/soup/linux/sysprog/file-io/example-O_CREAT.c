#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    const char* filename = argv[1];
    int fd;
    const char bytes_to_write[] = "Howdy\n";
    ssize_t nwritten;

    fd = open(filename, O_WRONLY|O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    nwritten = write(fd, bytes_to_write, sizeof(bytes_to_write));
    if (nwritten == -1) {
        perror("write");
        return 2;
    }

    close(fd);
    return 0;
}
