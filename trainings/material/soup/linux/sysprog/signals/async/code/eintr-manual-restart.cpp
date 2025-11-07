#include <unistd.h>
#include <signal.h>
#include <print>


static void handler(int signal)
{
    static const char msg[] = "signal handler\n";
    write(STDOUT_FILENO, msg, sizeof(msg));            // <-- async-signal-safe
}

int main()
{
    std::println("PID={}", getpid());

    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGTERM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    while (true) {
        char c;
        ssize_t nread = read(STDIN_FILENO, &c, 1);
        if (nread == -1) {
            if (errno == EINTR)
                continue;
            else {
                perror("read");
                return 1;
            }
        }
    }
    return 0;
}
