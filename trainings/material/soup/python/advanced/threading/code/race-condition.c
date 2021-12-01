#include <pthread.h>
#include <assert.h>
#include <stdio.h>


static int integer;
static const int ntimes = 10000000;

void* increment_background(void* arg)
{
    int i;
    for (i=0; i<ntimes; i++)
        integer++;
    return NULL;
}

int main (void)
{
    pthread_t tid;
    int error, i;

    error = pthread_create(&tid, NULL, increment_background, NULL);
    assert(!error);

    for (i=0; i<ntimes; i++)
        integer++;

    error = pthread_join(tid, NULL);
    assert(!error);

    printf("final value: %d\n", integer);
    return 0;
}
