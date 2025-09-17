#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <print>

int main()
{
    int fd = open("/etc/passwd", O_RDWR);
    if (fd == -1) {
        char buf[64];                                  // <-- *might* be used
        const char* errstr = strerror_r(errno, buf, sizeof(buf));
        std::println("open failed: {} ({})", errstr, errno);
        return 1;
    }

    return 0;
}
