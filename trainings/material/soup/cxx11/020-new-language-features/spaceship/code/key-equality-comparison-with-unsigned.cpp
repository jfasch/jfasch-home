#include <cassert>

struct key
{
    unsigned id;
    bool operator==(unsigned rhs) const
    {
        return id == rhs;
    }
};

int main()
{
    key k{42};
    assert(k == 42);                                   // <-- explicitly defined in type
    assert(k != 666);                                  // <-- automatic !operator==()
    assert(42 == k);                                   // <-- freaky
    assert(666 != k);                                  // <-- freaky
    return 0;
}
