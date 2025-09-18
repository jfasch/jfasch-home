#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <print>

int main()
{
    int variable = 42;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    
    if (pid == 0) {
        variable = 666;                                // <-- copy-on-write
        return 7;
    }
    else {
        wait(NULL);                                    // <-- be sure child has touched variable
        std::println("parent: variable=={}", variable);
        return 0;
    }
}
