#include <unistd.h>
#include <signal.h>
#include <print>

int main()
{
    std::println("PID={}", getpid());

    sigset_t interest;
    sigemptyset(&interest);
    sigaddset(&interest, SIGTERM);
    sigaddset(&interest, SIGINT);
    sigaddset(&interest, SIGUSR1);
    sigaddset(&interest, SIGUSR2);

    int rv = sigprocmask(SIG_BLOCK, &interest,         // <-- inhibit async delivery
                         nullptr);
    if (rv == -1) {
        perror("sigwait");
        return 1;
    }

    bool quit = false;
    while (!quit) {
        int signal;
        rv = sigwait(&interest, &signal);              // <-- read directly from kernel
        if (rv == -1) {
            perror("sigwait");
            return 1;
        }

        switch (signal) {                              // <-- same logic as in self-pipe
            case SIGTERM:
            case SIGINT:
                std::println("terminating");
                quit = true;
                break;
            case SIGUSR1:
                std::println("doing this");
                break;
            case SIGUSR2:
                std::println("doing that");
                break;
        }
    }
    return 0;
}
