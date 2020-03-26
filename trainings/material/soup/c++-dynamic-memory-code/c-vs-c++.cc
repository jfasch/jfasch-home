#include <gtest/gtest.h>

#include <stdlib.h>


TEST(MallocFree, SingleInteger)
{
    int* ip = (int*)malloc(sizeof(int));
    *ip = 666;
    free(ip);
}

TEST(MallocFree, ArrayOfInteger)
{
    int* ip = (int*)malloc(28*sizeof(int));
    ip[0] = 42;
    ip[27] = 7;
    free(ip);
}

TEST(NewDelete, SingleInteger)
{
    int* ip = new int;
    *ip = 666;
    delete ip;
}

TEST(NewDelete, ArrayOfInteger)
{
    int* ip = new int[28];
    ip[0] = 42;
    ip[27] = 7;
    delete[] ip;
}
