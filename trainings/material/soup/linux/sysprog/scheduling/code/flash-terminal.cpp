// g++ -o /tmp/flash-terminal flash-terminal.cpp

#include <unistd.h>
#include <time.h>


int main()
{
    bool is_reverse = false;
    static char reverse[] = "\033[7m";
    static char normal[] = "\033[0m";

    while (true) {
        if (is_reverse)
            write(STDOUT_FILENO, reverse, sizeof(reverse));
        else
            write(STDOUT_FILENO, normal, sizeof(normal));

        is_reverse = !is_reverse;
        
        struct timespec interval_ts = {
            /*sec*/ 2, 
            /*nsec*/ 0
        };
        nanosleep(&interval_ts, NULL);
    }

    return 0;
}
