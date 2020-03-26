#include <gtest/gtest.h>

#include <stdlib.h>


TEST(Bug, MemoryLeak)
{
    int* ip = (int*)malloc(sizeof(int));
    (void)ip; // avoid "unused" warning
}

TEST(Bug, ArrayBoundsWrite)
{
    int* ip = (int*)malloc(28*sizeof(int));
    ip[0] = 42;
    ip[27] = 7;
    ip[28] = 666;
    free(ip);
}

TEST(Bug, DeleteMismatch)
{
    int* ip = new int[28];
    delete[] ip;
}
