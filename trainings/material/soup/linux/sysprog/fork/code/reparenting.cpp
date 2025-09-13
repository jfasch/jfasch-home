#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == 0) {
        char one_byte;
        ssize_t nread = read(STDIN_FILENO, &one_byte, 1);
        assert(nread == 1);
    }
    else {
        std::println("parent pid = {}, child pid = {}", getpid(), pid);
        std::println("parent exits");
        exit(0);
    }
}
