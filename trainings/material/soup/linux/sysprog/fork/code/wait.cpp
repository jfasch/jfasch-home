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
        return 42;
    }
    else {
        std::println("parent pid = {}, child pid = {}", getpid(), pid);

        pid_t waited_for = wait(NULL);                 // <-- wait until child ... terminates?
        std::println("child {} has changed state", waited_for);
        return 0;
    }
}
