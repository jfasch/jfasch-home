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

    int rv = sigaction(SIGRTMIN+5, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    sigset_t blocked;
    sigemptyset(&blocked);
    sigaddset(&blocked, SIGRTMIN+5);

    rv = sigprocmask(SIG_BLOCK, &blocked, nullptr);
    if (rv == -1) {
        perror("sigprocmask(SIG_BLOCK)");
        return 1;
    }
    std::println("blocked SIGRTMIN+5 ({}), "           // <-- output its number so we know
                 "<RETURN> to continue", SIGRTMIN+5);

    char c;
    rv = read(STDIN_FILENO, &c, 1);
    if (rv == -1) {
        perror("read");
        return 1;
    }

    sigset_t pending;
    rv = sigpending(&pending);
    if (rv == -1) {
        perror("sigpending");
        return 1;
    }
    if (sigismember(&pending, SIGRTMIN+5))
        std::println("SIGRTMIN+5 pending");

    rv = sigprocmask(SIG_UNBLOCK, &blocked, nullptr);  // <-- handler is called as many times 
                                                       //     as signal instances are pending
    if (rv == -1) {
        perror("sigprocmask(SIG_UNBLOCK)");
        return 1;
    }
    std::println("unblocked SIGRTMIN+5, <RETURN> to continue");

    rv = read(STDIN_FILENO, &c, 1);
    if (rv == -1) {
        perror("read");
        return 1;
    }

    return 0;
}
