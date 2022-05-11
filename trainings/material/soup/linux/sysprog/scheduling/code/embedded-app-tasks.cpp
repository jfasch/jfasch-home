// g++ -o /tmp/embedded-app-tasks embedded-app-tasks.cpp -lrt -lpthread

#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

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


static void* update_status_func(void*)
{
    // initial expiration in a second
    struct timespec initial_ts = {
        /*sec*/ 1,
        /*nsec*/ 0
    };
    nanosleep(&initial_ts, NULL);

    while (true) {
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

        // interval
        struct timespec interval_ts = {
            /*sec*/ 0,
            /*nsec*/ 1000*1000*1000 / 2 // half a second
        };
        nanosleep(&interval_ts, NULL);
    }

    return NULL;
}

static void* show_status_func(void*)
{
    // initial expiration in a second
    struct timespec initial_ts = {
        /*sec*/ 1,
        /*nsec*/ 0
    };
    nanosleep(&initial_ts, NULL);

    while (true) {
        write(STDOUT_FILENO, status.display, sizeof(status.display));

        struct timespec interval_ts = {
            /*sec*/ 1, 
            /*nsec*/ 0
        };
        nanosleep(&interval_ts, NULL);
    }

    return NULL;
}

int main()
{
    // initialize application
    {
        status.state = INITIAL;
        status.tick_counter = 0;
        strcpy(status.display, "----------\n");
    }

    // start update task
    {
        pthread_t update_task;
        int error = pthread_create(&update_task, NULL, update_status_func, NULL);
        if (error) {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            return 1;
        }
    }

    // start show task
    {
        pthread_t show_task;
        int error = pthread_create(&show_task, NULL, show_status_func, NULL);
        if (error) {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            return 1;
        }
    }

    while (true)
        pause();  // or do power management, on a real bare metal
                  // platform

    return 0;
}
