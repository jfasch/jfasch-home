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

    rv = sigprocmask(SIG_BLOCK, &blocked, nullptr);    // <-- block SIGUSR1
    if (rv == -1) {
        perror("sigprocmask(SIG_BLOCK)");
        return 1;
    }
    std::println("blocked SIGUSR1, <RETURN> to continue");

    char c;
    rv = read(STDIN_FILENO, &c, 1);                    // <-- send SIGUSR1 from another terminal
                                                       //     - *not* delivered
                                                       //     - read() waits for me
    if (rv == -1) {
        perror("read");
        return 1;
    }

    rv = sigprocmask(SIG_UNBLOCK, &blocked, nullptr);  // <-- unblock SIGUSR1 -> delivered *immediately*
                                                       //     on return to userspace
    if (rv == -1) {
        perror("sigprocmask(SIG_UNBLOCK)");
        return 1;
    }

    std::println("done unblocking SIGUSR1");

    return 0;
}
