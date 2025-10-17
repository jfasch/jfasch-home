#include <fcntl.h>
#include <print>

int main()
{
    int fd = open("/etc/passwd", O_WRONLY);
    if (fd == -1) {
        std::println("open failed");                   // <-- might encounter an error, somewhere, internally
        std::println("errno=={}", errno);              // <-- errno might not be open's anymore
        return 1;
    }

    return 0;
}
