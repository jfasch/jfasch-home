#include "foo.h"
#include <iostream>

extern Foo other_foo;
Foo my_foo{42 + other_foo.number};

int main()
{
    std::cout << my_foo.number << std::endl;
    return 0;
}
