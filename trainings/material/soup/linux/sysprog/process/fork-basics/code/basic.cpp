#include <unistd.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == 0) {                                    // <-- child
        std::println("child: pid = {}, ppid = {}", 
                     getpid(), getppid());
        return 0;                                      // <-- careful!!
    }
    else {                                             // <-- parent
        std::println("parent: pid = {}, child pid = {}", 
                     getpid(), pid);
        return 0;                                      // <-- careful!!
    }
}
