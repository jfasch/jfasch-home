#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <print>


static void handler(int signal)
{
    static const char msg[] = "signal handler\n";
    write(STDOUT_FILENO, msg, sizeof(msg));
}

int main()
{
    std::println("PID={}", getpid());

    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGUSR1, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    sigset_t blocked;
    sigemptyset(&blocked);
    sigaddset(&blocked, SIGUSR1);

    rv = sigprocmask(SIG_BLOCK, &blocked, nullptr);
    if (rv == -1) {
        perror("sigprocmask(SIG_BLOCK)");
        return 1;
    }

    std::println("send me a SIGUSR1, and press <return> when done");
    char c;
    rv = read(STDIN_FILENO, &c, 1);
    if (rv == -1) {
        perror("read");
        return 1;
    }

    sigset_t pending;
    rv = sigpending(&pending);                         // <-- ask kernel what's pending
    if (rv == -1) {
        perror("sigpending");
        return 1;
    }
    if (sigismember(&pending, SIGUSR1))                // <-- it's SIGUSR1
        std::println("SIGUSR1 pending");
    else 
        std::println("Gosh!!");

    rv = sigprocmask(SIG_UNBLOCK, &blocked, nullptr);
    if (rv == -1) {
        perror("sigprocmask(SIG_UNBLOCK)");
        return 1;
    }

    std::println("done unblocking SIGUSR1");

    return 0;
}
