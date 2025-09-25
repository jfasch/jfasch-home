#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <print>

static volatile sig_atomic_t quit = 0;                 // <-- special "atomic" type

static void handler(int signal)
{
    if (signal == SIGTERM || signal == SIGINT)
        quit = 1;
}

int main()
{
    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGTERM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGTERM)");
        return 1;
    }
    rv = sigaction(SIGINT, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGINT)");
        return 1;
    }

    while (!quit) {
        char c;
        rv = read(STDIN_FILENO, &c, 1);
        if (rv == -1) {
            if (errno == EINTR)                        // <-- restart manually
                continue;
            else {
                perror("read");
                return 1;
            }
        }
    }

    std::println("bye");
    return 0;
}
