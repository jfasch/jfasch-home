#include "msg.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;


int main()
{
    mqd_t q = mq_open("/meine-queue", O_RDONLY);
    if (q == -1) {
        perror("mq_open");
        return 1;
    }

    msg msg;
    unsigned int prio;
    ssize_t nread = mq_receive(q, (char*)&msg, sizeof(msg), &prio);
    if (nread == -1) {
        perror("mq_receive");
        return 1;
    }

    cout << "prio: " << prio << endl;
    cout << "channel: " << msg.channel << endl;
    cout << "timestamp: " << msg.timestamp << endl;
    cout << "value: " << msg.value << endl;

    return 0;
}
