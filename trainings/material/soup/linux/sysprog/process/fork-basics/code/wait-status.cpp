#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        sleep(3);
        std::println("child (PID={}): exiting", getpid());
        return 7;
    }
    else {
        std::println("parent (PID={}): waiting for child (PID={})", getpid(), pid);

        int status;
        pid_t waited_for = wait(&status);
        if (waited_for == -1) {
            perror("wait");
            return 1;
        }
        std::println("child {0} has changed state, status {1:#x}, {1:#b}", waited_for, status);

        if (WIFEXITED(status))                         // <-- what if not? alternatives?
            std::println("child has exited with exit status {}", WEXITSTATUS(status));
        return 0;
    }
}
