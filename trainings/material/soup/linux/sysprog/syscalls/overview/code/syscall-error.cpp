#include <fcntl.h>
#include <unistd.h>
#include <print>

int main()
{
    int fd = open("/etc/passwd", O_WRONLY);            // <-- only root can do this
    if (fd == -1) {                                    // <-- "open failed"
        std::println("open failed with errno {}", 
                     errno);                           // <-- here's how it failed
        return 1;
    }
    return 0;
}
