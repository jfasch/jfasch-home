#include <unistd.h>
#include <signal.h>
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

    int rv = sigaction(SIGTERM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    char c;
    rv = read(STDIN_FILENO, &c, 1);                    // <-- blocks until keypress (possibly long)
    if (rv == -1) {
        perror("read");
        return 1;
    }
    return 0;
}
