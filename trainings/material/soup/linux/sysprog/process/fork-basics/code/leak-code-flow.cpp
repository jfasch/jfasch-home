#include <unistd.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
        std::println("child: pid = {}, ppid = {}", getpid(), getppid());
    else
        std::println("parent: pid = {}, child pid = {}", getpid(), pid);

    std::println("goodbye from {}", getpid());
    return 0;
}
