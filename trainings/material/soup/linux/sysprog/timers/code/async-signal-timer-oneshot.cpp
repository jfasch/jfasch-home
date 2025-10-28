#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static void handler(int signal)
{
    static const char msg[] = "timer expired\n";
    write(STDOUT_FILENO, msg, sizeof(msg));
}

int main()
{
    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGRTMIN, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    timer_t timer;
    sigevent event = {0};
    event.sigev_notify = SIGEV_SIGNAL;
    event.sigev_signo = SIGRTMIN;
    
    rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
    if (rv == -1) {
        perror("timer_create");
        return 1;
    }

    struct itimerspec delta = {
        {0,0},                                         // <-- one-shot (no interval)
        {3,0},                                         // <-- {sec,nsec}
    };

    rv = timer_settime(timer, 0 /*relative*/,
                       &delta,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime");
        return 1;
    }

    rv = pause();
    if (rv == -1) {
        if (errno == EINTR)
            std::println("interrupted; now having all the options of async signal handling");
        else {
            perror("pause");
            return 1;
        }
    }

    return 0;
}
