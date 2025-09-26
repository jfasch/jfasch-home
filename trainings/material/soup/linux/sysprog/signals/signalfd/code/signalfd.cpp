#include <unistd.h>
#include <sys/signalfd.h>
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

    int rv = sigprocmask(SIG_BLOCK, &interest, nullptr);
    if (rv == -1) {
        perror("sigprocmask");
        return 1;
    }

    int fd = signalfd(-1, &interest, 0);               // <-- new fd, no flags

    bool quit = false;
    while (!quit) {
        signalfd_siginfo signals[4];                   // <-- we handle 4 different signals
        ssize_t nread = read(fd,                       // <-- read max 4 signals
                             signals, sizeof(signals));
        if (nread == -1) {
            perror("read");
            return 1;
        }

        for (size_t i=0; i<sizeof(signals)/sizeof(signalfd_siginfo); i++) {
            switch (signals[i].ssi_signo) {            // <-- disregard other structure members
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
    }
    return 0;
}
