#include <fcntl.h>
#include <print>

int main()
{
    int fd = open("/etc/passwd", O_RDWR);
    if (fd == -1) {
        std::println("open failed, errno=={}", errno);
        return 1;
    }

    return 0;
}
