#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static void handler(union sigval v)
{
    static const char msg[] = "signal handler\n";
    write(STDOUT_FILENO, msg, sizeof(msg));
}

int main()
{
    timer_t timer;
    sigevent event = {0};
    event.sigev_notify = SIGEV_THREAD;                 // <-- threaded notification
    event.sigev_notify_function = handler;             // <-- function to be called in thread context

    int rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
    if (rv == -1) {
        perror("timer_create");
        return 1;
    }

    /* timer activation */
    struct itimerspec sp = {
        .it_interval = {.tv_sec=0, .tv_nsec=0},        // <-- zero interval -> one-shot
        .it_value    = {.tv_sec=3, .tv_nsec=0},        // <-- expire after {sec,nsec}
    };
    rv = timer_settime(timer, 0 /*relative*/,
                       &sp,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime");
        return 1;
    }

    rv = pause();
    if (rv == -1) {
        if (errno == EINTR)
            std::println("interrupted");
        else {
            perror("pause");
            return 1;
        }
    }

    return 0;
}
