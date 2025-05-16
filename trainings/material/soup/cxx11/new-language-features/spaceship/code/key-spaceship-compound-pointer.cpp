#include <compare>
#include <cstring>
#include <cassert>

struct key
{
    unsigned primary;
    const char* secondary;

    std::strong_ordering operator<=>(const key& rhs) const
    {
        if (std::strong_ordering cmp = primary <=> rhs.primary; cmp != std::strong_ordering::equal)
            return cmp;

        // .primary are equal -> fallback to strcmp .secondary
        int cmp1 = std::strcmp(secondary, rhs.secondary);
        if (cmp1 < 0)
            return std::strong_ordering::less;
        else if (cmp1 == 0)
            return std::strong_ordering::equal;
        else
            return std::strong_ordering::greater;
    }

    bool operator==(const key& rhs) const
    {
        return !(*this < rhs) && !(*this > rhs);
    }
};

int main()
{
    key k1{42, "a"};
    key k2{42, "b"};
    key k3{43, "b"};

    assert(k1 < k2);
    assert(k1 == k1);
    assert(k1 != k2);
    assert(k1 <= k1);
    assert(k1 <= k2);
    assert(k2 >= k2);
    assert(k2 >= k1);
    assert(k2 > k1);

    assert(k1 < k3);
    assert(k2 < k3);

    return 0;
}
