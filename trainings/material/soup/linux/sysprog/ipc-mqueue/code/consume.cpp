#include <mqueue.h>
#include <stdio.h>

struct my_message
{
    int x, y;
};

int main()
{
    mqd_t q = mq_open("/my-queue", O_RDONLY);
    if (q == -1) {
        perror("mq_open");
        return 1;
    }

    struct my_message msg;
    unsigned int prio;
    ssize_t nread = mq_receive(q, (char*)&msg, sizeof(msg), &prio);
    if (nread == -1) {
        perror("mq_receive");
        return 1;
    }

    printf("prio=%u, x=%d, y=%d\n", prio, msg.x, msg.y);
    return 0;
}
