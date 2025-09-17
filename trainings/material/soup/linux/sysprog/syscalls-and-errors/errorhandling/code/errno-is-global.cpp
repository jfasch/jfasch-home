#include <fcntl.h>
#include <print>

int main()
{
    int fd = open("/etc/passwd", O_RDWR);
    if (fd == -1) {
        std::println("open failed");
        std::println("errno=={}", errno);              // <-- errno could have changed by previous println()
        return 1;
    }

    return 0;
}
