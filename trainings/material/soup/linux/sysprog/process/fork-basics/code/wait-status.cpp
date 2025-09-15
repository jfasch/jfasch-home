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
        std::println("child exiting with status 42");
        exit(42);                                      // <-- same as "return 42" from main()
    }
    else {
        std::println("parent pid = {}, child pid = {}", getpid(), pid);

        int status;
        pid_t waited_for = wait(&status);
        std::println("child {0} has changed state, status {1:#x}, {1:#b}", waited_for, status);

        if (WIFEXITED(status))                         // <-- what if not? alternatives?
            std::println("child has exited with exit status {}", WEXITSTATUS(status));

        return 0;
    }
}
