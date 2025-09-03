#include <compare>
#include <cassert>

struct key
{
    unsigned id;
    std::strong_ordering operator<=>(const key& rhs) const = default;
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
