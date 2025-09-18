#include <unistd.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) {
        std::println("child: pid = {}, ppid = {}", 
                     getpid(), getppid());
        /* <-- falling through into unconditional code*/;
    }
    else {
        std::println("parent: pid = {}, child pid = {}", 
                     getpid(), pid);
        /* <-- falling through into unconditional code*/;
    }

    std::println("goodbye from {}", getpid());         // <-- executed by both
    return 0;
}
