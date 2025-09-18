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

    close(1);                                          // <-- or use STDOUT_FILENO for clarity
    int dupfd = dup(origfd);                           // <-- dupfd == STDOUT_FILENO
    if (dupfd == -1) {
        perror("dup");
        return 1;
    }

    std::println("hah, this won't be seen on the terminal");

    return 0;
}
