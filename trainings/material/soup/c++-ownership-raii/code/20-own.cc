#include <unistd.h>


class Owns
{
public:
    Owns(size_t n)
    : _mem(new char[n]) {}
    ~Owns() { delete[] _mem; }
private:
    char* _mem;
};

int main()
{
    Owns owns(28);
    return 0;
}
