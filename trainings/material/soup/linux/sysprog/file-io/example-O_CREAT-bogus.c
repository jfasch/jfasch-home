#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    const char* filename = argv[1];
    int fd;

    fd = open(filename, O_WRONLY|O_CREAT);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    close(fd);
    return 0;
}
