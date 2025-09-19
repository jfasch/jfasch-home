#include <unistd.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);                                       // <-- same as "return 1;"
    }

    if (pid == 0) {
        std::println("child: pid = {}, ppid = {}", 
                     getpid(), getppid());
        exit(0);                                       // <-- same as "return 0;"
    }
    else {
        std::println("parent: pid = {}, child pid = {}", 
                     getpid(), pid);
        exit(0);                                       // <-- same as "return 0;"
    }
}
