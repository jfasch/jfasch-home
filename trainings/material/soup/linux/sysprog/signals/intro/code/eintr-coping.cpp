#include <unistd.h>
#include <signal.h>
#include <print>


static void handler(int signal)
{
    static const char msg[] = "signal handler\n";
    write(STDOUT_FILENO, msg, sizeof(msg));            // <-- async-signal-safe
}

char read_one_byte() {
    while (true) {
        char c;
        int rv = read(STDIN_FILENO, &c, 1);
        if (rv == -1) {
            if (errno == EINTR)
                continue;                              // <-- restart
            else
                ;                                      // <-- and now? return error?
        }
        return c;
    }
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

    read_one_byte();
    return 0;
}
