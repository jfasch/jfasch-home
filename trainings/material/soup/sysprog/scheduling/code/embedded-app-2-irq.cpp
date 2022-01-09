// g++ -o /tmp/embedded-app-2-irq embedded-app-2-irq.cpp -lrt

#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

enum State
{
    INITIAL,
    RISING,
    FALLING
};


struct app_status {
    int state;
    int tick_counter;
    char display[12];
};
struct app_status status;

static void update_status(int)
{
    switch (status.state) {
        case INITIAL:
            if (status.tick_counter == 9)
                status.state = RISING;
            break;
        case RISING:
            status.display[status.tick_counter] = '/';
            if (status.tick_counter == 9)
                status.state = FALLING;
            break;
        case FALLING:
            status.display[status.tick_counter] = '\\';
            if (status.tick_counter == 9)
                status.state = RISING;
            break;
    }

    if (status.tick_counter < 9)
        status.tick_counter++;
    else 
        status.tick_counter = 0;
}

static void show_status(int)
{
    write(STDOUT_FILENO, status.display, sizeof(status.display));
}

int main()
{
    // initialize application
    {
        status.state = INITIAL;
        status.tick_counter = 0;
        strcpy(status.display, "----------\n");
    }

    // establish update timer handler
    {
        struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_handler = update_status;

        int error = sigaction(SIGRTMIN, &sa, NULL);
        if (error) {
            perror("sigaction");
            return 1;
        }
    }

    // create and start update timer
    {
        struct sigevent sev;
        memset(&sev, 0, sizeof(sev));
        sev.sigev_notify = SIGEV_SIGNAL;
        sev.sigev_signo = SIGRTMIN;

        timer_t timer;
        int error = timer_create(CLOCK_MONOTONIC, &sev, &timer);
        if (error) {
            perror("timer_create");
            return 1;
        }

        itimerspec tspec = {
            /*interval*/
            {
                /*sec*/ 0, 
                /*nsec*/ 1000*1000*1000 / 2 // half a second
            },
            /*initial expiration in a second*/
            {
                /*sec*/ 1,
                /*nsec*/ 0
            }
        };

        error = timer_settime(timer, 0, &tspec, NULL);
        if (error) {
            perror("timer_settime");
            return 1;
        }
    }

    // establish show timer handler
    {
        struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_handler = show_status;

        int error = sigaction(SIGRTMIN+1, &sa, NULL);
        if (error) {
            perror("sigaction");
            return 1;
        }
    }

    // create and start show timer
    {
        struct sigevent sev;
        memset(&sev, 0, sizeof(sev));
        sev.sigev_notify = SIGEV_SIGNAL;
        sev.sigev_signo = SIGRTMIN+1;

        timer_t timer;
        int error = timer_create(CLOCK_MONOTONIC, &sev, &timer);
        if (error) {
            perror("timer_create");
            return 1;
        }

        itimerspec tspec = {
            /*interval*/
            {
                /*sec*/ 1, 
                /*nsec*/ 0
            },
            /*initial expiration in a second*/
            {
                /*sec*/ 1,
                /*nsec*/ 0
            }
        };

        error = timer_settime(timer, 0, &tspec, NULL);
        if (error) {
            perror("timer_settime");
            return 1;
        }
    }

    while (true)
        pause();  // or do power management, on a real bare metal
                  // platform

    return 0;
}
