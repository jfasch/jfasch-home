#include <unistd.h>
#include <signal.h>
#include <list>
#include <print>


static std::list<int> my_numbers;

static void handler(int signal)
{
    for (int i=0; i<10; i++)
        my_numbers.push_back(i);
}

int main()
{
    std::println("PID={}", getpid());

    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGUSR1, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    while (true) {
        if (my_numbers.size() > 100)
            my_numbers.clear();
        for (int i=0; i<10; i++)
            my_numbers.push_back(i);
        pause();
    }

    return 0;
}
