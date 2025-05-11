#include <cassert>

struct key
{
    unsigned id;
    bool operator< (const key& rhs) const
    {
        return id < rhs.id;
    }
    bool operator==(const key& rhs) const { return !(*this < rhs) && !(rhs < *this); }
    bool operator!=(const key& rhs) const { return !(*this == rhs); }
    bool operator<=(const key& rhs) const { return *this < rhs || *this == rhs; }
    bool operator>=(const key& rhs) const { return !(*this < rhs); }
    bool operator> (const key& rhs) const { return rhs < *this && *this != rhs; }
};

int main()
{
    key k1{42};
    key k2{666};

    assert(k1 < k2);
    assert(k1 == k1);
    assert(k1 != k2);
    assert(k1 <= k1);
    assert(k1 <= k2);
    assert(k2 >= k2);
    assert(k2 >= k1);
    assert(k2 > k1);

    return 0;
}
