#include "msg.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


int main()
{
    mqd_t q = mq_open("/meine-queue", O_WRONLY);
    if (q == -1) {
        perror("mq_open");
        return 1;
    }

    msg msg;
    msg.timestamp = time(NULL); // seconds since epoch, roughly
    msg.value = 42.0;
    msg.channel = 7;

    int error = mq_send(q, (const char*)&msg, sizeof(msg), /*prio*/0);
    if (error) {
        perror("mq_send");
        return 1;
    }

    return 0;
}
