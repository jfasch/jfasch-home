#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <assert.h>
#include <print>

int sig_channel_read, sig_channel_write;

static void handler(int signal)
{
    ssize_t nwritten = write(sig_channel_write,        // <-- send command to main loop
                             &signal, sizeof(signal));
    if (nwritten == -1)
        _exit(2);                                      // <-- perror (and even exit()) not async-signal-safe
}


int main()
{
    std::println("PID={}", getpid());

    int pipe_ends[2];
    int rv = pipe(pipe_ends);
    if (rv == -1) {
        perror("pipe");
        return 1;
    }
    sig_channel_read = pipe_ends[0];
    sig_channel_write = pipe_ends[1];

    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    rv = sigaction(SIGTERM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGTERM)");
        return 1;
    }
    rv = sigaction(SIGINT, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGINT)");
        return 1;
    }
    rv = sigaction(SIGUSR1, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGUSR1)");
        return 1;
    }
    rv = sigaction(SIGUSR2, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGUSR2)");
        return 1;
    }

    bool quit = false;
    while (!quit) {
        int signal;
        ssize_t nread = read(sig_channel_read,         // <-- read commands from signal context
                             &signal, sizeof(signal));
        if (nread == -1) {
            if (errno == EINTR)                        // <-- restart manually
                continue;
            else {
                perror("read");
                return 1;
            }
        }
        assert(nread==sizeof(signal));

        switch (signal) {                              // <-- interpret commands
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
