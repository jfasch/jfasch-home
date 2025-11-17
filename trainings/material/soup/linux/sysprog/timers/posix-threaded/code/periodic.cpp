#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static void handler(union sigval v)                    // <-- callback-data
{
    static const char msg[] = "timer expired\n";
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
        {1,0},
        {3,0},
    };
    rv = timer_settime(timer, 0 /*relative*/,
                       &sp,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime");
        return 1;
    }

    while (true) {
        rv = pause();
        if (rv == -1) { 
            if (errno == EINTR)
                std::println("interrupted");
            else {
                perror("pause");
                return 1;
            }
        }
    }

    return 0;
}
