#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <assert.h>


int main()
{
    int fd = open("/etc/passwd", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat stat;
    int error = fstat(fd, &stat);
    if (error) {
        perror("fstat");
        return 1;
    }

    void* addr = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    close(fd);

    ssize_t nwritten = write(STDOUT_FILENO, addr, stat.st_size);
    if (nwritten == -1) {
        perror("write");
        return 1;
    }
    assert(nwritten != 0);

    return 0;
}
