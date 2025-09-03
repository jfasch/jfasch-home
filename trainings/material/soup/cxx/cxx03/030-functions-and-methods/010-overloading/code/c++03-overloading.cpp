#include <iostream>

void f(int i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void f(char* s)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}


int main()
{
    int i = 42;
    f(i);

    char s[] = "howdy";
    f(s);

    return 0;
}
