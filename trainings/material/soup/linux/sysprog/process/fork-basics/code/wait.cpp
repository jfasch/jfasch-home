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

        pid_t waited_for = wait(NULL);                 // <-- wait, no termination status needed
        if (waited_for == -1) {
            perror("wait");
            return 1;
        }
        std::println("parent (PID={}): child {} terminated", getpid(), waited_for);
        return 0;
    }
}
