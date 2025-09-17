#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <print>

int main()
{
    int fd = open("/etc/passwd", O_RDWR);
    if (fd == -1) {
        const char* errstr = strerror(errno);
        std::println("open failed: {} ({})", errstr, errno);
        return 1;
    }

    return 0;
}
