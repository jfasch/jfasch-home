#include <iostream>
#include <cstring>


class X
{
public:
    X(size_t size)
    : data(new int[size]),
      size(size)
    {
        std::cerr << "X(size_t)" << std::endl;
    }

    X(const X& x)
    : X(x.size)
    {
        std::cerr << "X(const X&)" << std::endl;
        memcpy(data, x.data, sizeof(int)*x.size);
    }
    
    X(X& x) 
    : data(x.data),
      size(x.size)
    {
        std::cerr << "X(X&)" << std::endl;
        x.data = 0;
        x.size = 0;
    }
    ~X()
    { 
        std::cout << "~X(): data=" << data << std::endl; 
        if (data != 0)
            delete[] data;
    }

    int *data;
    size_t size;
};

X f()
{
    X x(100);
    return x;
}

int main()
{
    std::cerr << "*** init from f() (sigh: RVO)" << std::endl;
    {
        X x = f();
    }
    std::cerr << "*** init from non-const" << std::endl;
    {
        X x(100);
        X y(x); // non-const -> moved -> x invalid
    }
    std::cerr << "*** init from const" << std::endl;
    {
        const X x(100);
        X y(x); // const (no other choice)
    }
}
