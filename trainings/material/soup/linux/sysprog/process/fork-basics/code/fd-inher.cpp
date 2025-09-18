#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <print>

int main()
{
    int fd = open("/tmp/somefile", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {                                    // <-- child
        char one_byte;
        ssize_t nread = read(fd, &one_byte, 1);
        assert(nread == 1);
        std::println("child has read one byte: {0}/{0:#x}", one_byte);
        return 0;
    }
    else {                                             // <-- parent
        std::println("parent pid = {}, child pid = {}", getpid(), pid);

        char one_byte;
        ssize_t nread = read(fd, &one_byte, 1);
        assert(nread == 1);
        std::println("parent has read one byte: {0}/{0:#x}", one_byte);
        return 0;
    }
}
