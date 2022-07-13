#include "string-10.h"

int main()
{
    String s1("hello");
    String s2 = s1;     // <--- compiler-generated copy ctor
    return 0;
}
