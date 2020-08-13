#include <unistd.h>


class Allocates
{
public:
    Allocates(size_t n)
    : _mem(new char[n]) {}
private:
    char* _mem;
};

int main()
{
    Allocates allocs(28);
    return 0;
}
