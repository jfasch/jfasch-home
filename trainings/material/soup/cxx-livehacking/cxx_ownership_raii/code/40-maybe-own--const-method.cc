#include <unistd.h>
#include <string.h>


class MaybeOwns
{
public:
    MaybeOwns(size_t n)
    : _mem(new char[n]) {}
    ~MaybeOwns() { delete[] _mem; }

    char* mem() const { return _mem; }

private:
    char* _mem;
};

int main()
{
    MaybeOwns mo(28);
    char* whose = mo.mem();
    strcpy(whose, "You are mine!");
    delete[] whose;
    return 0;
}
