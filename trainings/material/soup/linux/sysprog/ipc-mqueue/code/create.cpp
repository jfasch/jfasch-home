#include <mqueue.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

struct my_message
{
    int x, y;
};

int main()
{
    struct mq_attr attr = {
        .mq_maxmsg = 10,
        .mq_msgsize = sizeof(my_message)
    };
    mqd_t q = mq_open("/my-queue", O_CREAT|O_EXCL, 0666, &attr);
    if (q == -1) {
        perror("mq_open");
        return 1;
    }

    return 0;
}
