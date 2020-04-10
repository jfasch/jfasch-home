#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;


// single items allocation in C
TEST(MallocFree, SimpleInteger)
{
    void* vp = malloc(sizeof(int));
    //int* ip = (int*)vp;
    int* ip = static_cast<int*>(vp);
    *ip = 42;
    free(ip);
}

// single items allocation in C++
TEST(NewDelete, SimpleInteger)
{
    int* ip = new int;
    *ip = 42;
    delete ip;
}

// array allocation in C: no different than single item allocation,
// only larger. the user has to deal with void* anyway.
TEST(MallocFree, IntegerArray)
{
    int* ia = (int*)malloc(28 * sizeof(int));
    ia[0] = 42;
    *(ia+6) = 666;
    ia[6] = 666;
    free(ia);
}

// array allocation in C++: new[]; note the delete[]!
TEST(NewDelete, IntegerArray)
{
    int* ia = new int[28];
    ia[0] = 42;
    *(ia+6) = 666;
    ia[6] = 666;
    ia[27] = 7;
    delete[] ia;
}

TEST(NewDelete, StringArray)
{
    string* sa = new string[28];
    sa[7] = "hallo";
    sa[8] = "joerg";
    delete[] sa;
}
