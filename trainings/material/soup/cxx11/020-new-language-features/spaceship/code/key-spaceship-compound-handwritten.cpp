#include <compare>
#include <cassert>

struct key
{
    unsigned primary;
    unsigned secondary;
    bool operator<(const key& rhs) const
    {
        if (primary != rhs.primary)
            return primary < rhs.primary;
        else
            return secondary < rhs.secondary;
    }
};

int main()
{
    key k1{42, 1};
    key k2{42, 2};
    key k3{666, 1};

    assert(k1 < k2);
    assert(k1 < k3);

    return 0;
}
