#include <unistd.h>
#include <stdio.h>

int main()
{
    int pipe_ends[2];
    if (pipe(pipe_ends) == -1) {
        perror("pipe");
        return 1;
    }

    [[maybe_unused]] int read_end = pipe_ends[0];
    [[maybe_unused]] int write_end = pipe_ends[1];

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {                                    // <-- child
        // ...
    }
    else {                                             // <-- parent
        // ...
    }

    return 0;
}
