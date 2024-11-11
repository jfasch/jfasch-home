#include <mqueue.h>
#include <stdio.h>

struct my_message
{
    int x, y;
};

int main()
{
    mqd_t q = mq_open("/my-queue", O_WRONLY);
    if (q == -1) {
        perror("mq_open");
        return 1;
    }

    struct my_message msg = { 1, 2 };
    int error = mq_send(q, (const char*)&msg, sizeof(msg), /*prio*/0);
    if (error) {
        perror("mq_send");
        return 1;
    }

    return 0;
}
