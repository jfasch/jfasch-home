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
        exit(42);
    }
    else {
        std::println("parent pid = {}, child pid = {}", getpid(), pid);

        while (true) {
            int status;
            pid_t waited_for = waitpid(pid, &status, WUNTRACED|WCONTINUED);
            std::println("child {0} has changed state, status {1:#x}, {1:#b}", waited_for, status);

            if (WIFEXITED(status)) {
                std::println("child has regularly exited with exit status {}", WEXITSTATUS(status));
                break;
            }
            else if (WIFSIGNALED(status)) {
                std::println("child has been blown out of the water by signal {} (core dumped: {})", WTERMSIG(status), WCOREDUMP(status));
                break;
            }
            else if (WIFSTOPPED(status))
                std::println("child has been stopped by signal {}", WSTOPSIG(status));
            else if (WIFCONTINUED(status))
                std::println("child has been continued");
        }
            
        return 0;
    }
}
