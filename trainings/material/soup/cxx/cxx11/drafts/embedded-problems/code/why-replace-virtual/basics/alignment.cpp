#include <iostream>

struct Bar
{
    int i;
    char c;
};

struct Foo
{
    int i;
    int j;
    char c;
};


int main()
{
    std::cout << "alignof(int)" << alignof(int) << std::endl;
    std::cout << "alignof(Bar)" << alignof(Bar) << std::endl;
    std::cout << "alignof(Foo)" << alignof(Foo) << std::endl;

    return 0;
}
