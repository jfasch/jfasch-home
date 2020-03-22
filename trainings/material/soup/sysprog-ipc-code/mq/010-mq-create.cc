#include "msg.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <stdio.h>


int main()
{
    mq_attr attr;
    memset(&attr, 0, sizeof(attr));
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(msg);
    mqd_t q = mq_open("/meine-queue", O_CREAT|O_EXCL, 0666, &attr);
    if (q == -1) {
        perror("mq_open");
        return 1;
    }

    return 0;
}
