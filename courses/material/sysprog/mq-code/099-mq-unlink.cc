#include <mqueue.h>
#include <stdio.h>


int main()
{
    int error = mq_unlink("/meine-queue");
    if (error) {
        perror("mq_unlink");
        return 1;
    }
    return 0;
}
