#pragma once

#include <pthread.h>

struct Data
{
    pthread_mutex_t lock;
#   define DATA_NAME_SIZE 32
    char name[DATA_NAME_SIZE];
    int value;
    int valid;
};
