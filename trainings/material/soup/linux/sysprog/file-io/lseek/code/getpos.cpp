#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <print>

int main()
{
    int fd = open("/etc/passwd", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    off64_t pos = lseek64(fd, 0, SEEK_CUR);
    if (pos == -1) {
        perror("lseek");
        return 1;
    }

    std::println("initial offset: {}", pos);

    char buf[10];
    ssize_t nread = read(fd, buf, 10);
    if (nread == -1) {
        perror("read");
        return 1;
    }

    pos = lseek64(fd, 0, SEEK_CUR);
    if (pos == -1) {
        perror("lseek");
        return 1;
    }

    std::println("offset after 10 bytes read: {}", pos);

    return 0;                                          // <-- fd automatically closed at exit
}
