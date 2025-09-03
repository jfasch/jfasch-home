#include <iostream>


struct Foo
{
    Foo(int i, int j, char c)
    : i{i},
      j{j},
      c{c}
    {
        std::cout << "Foo::Foo(int,int,char)" << std::endl;
    }

    ~Foo()
    {
        std::cout << "Foo::~Foo()" << std::endl;
    }

    int i;
    int j;
    char c;
};

int main()
{
    void* mem = std::aligned_alloc(alignof(Foo), sizeof(Foo));
    Foo* f = new (mem) Foo(42, 666, 'x');
    std::cout << f->i << ',' << f->j << ',' << f->c << std::endl;
    f->~Foo();
    std::free(mem);

    return 0;
}
