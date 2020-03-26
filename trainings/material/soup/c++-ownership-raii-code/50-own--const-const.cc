#include <unistd.h>
#include <string.h>

#include <string>
#include <memory>


class MaybeOwns
{
public:
    MaybeOwns(size_t n)
    : _mem(new char[n]) {}
    ~MaybeOwns() { delete[] _mem; }

    const char* mem() const { return _mem; }

private:
    char* _mem;
};

int main()
{
    MaybeOwns mo(28);
    const char* whose = mo.mem();
    delete[] whose;
    return 0;
}
