#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
        pause();
    else {
        std::println("parent pid = {}, child pid = {}", getpid(), pid);
        std::println("parent exits");
        return 0;
    }
}
