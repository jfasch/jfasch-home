#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <print>

int main()
{
    int origfd = open("/tmp/somefile", O_WRONLY|O_CREAT|O_EXCL, 0666);
    if (origfd == -1) {
        perror("open");
        return 1;
    }

    int dupfd = dup(origfd);
    if (dupfd == -1) {
        perror("dup");
        return 1;
    }

    char content[] = "0123456789";
    ssize_t nwritten = 
        write(origfd, content, sizeof(content));       // <-- write via origfd
    if (nwritten == -1) {
        perror("write");
        return -1;
    }

    off64_t pos = lseek64(dupfd, 0, SEEK_CUR);         // <-- offset via dupfd
    if (pos == -1) {
        perror("lseek");
        return 1;
    }

    std::println("offset: {}", pos);

    return 0;                                          // <-- fds automatically closed at exit
}
