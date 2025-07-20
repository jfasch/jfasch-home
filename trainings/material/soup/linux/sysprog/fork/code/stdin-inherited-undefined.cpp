#include <unistd.h>
#include <assert.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == 0) {
        char one_byte;
        ssize_t nread = read(STDIN_FILENO, &one_byte, 1);
        assert(nread == 1);
        std::println("child has read one byte: {0}/{0:#x}", one_byte);
        return 0;
    }
    else {
        std::println("parent pid = {}, child pid = {}", getpid(), pid);

        char one_byte;
        ssize_t nread = read(STDIN_FILENO, &one_byte, 1);
        assert(nread == 1);
        std::println("parent has read one byte: {0}/{0:#x}", one_byte);
        return 0;
    }
}
