#include <compare>
#include <cassert>

struct key
{
    unsigned primary;
    double secondary;                                  // <-- no std::string_ordering
    std::strong_ordering operator<=>(const key& rhs) const = default;
};

int main()
{
    key k1{42, 1};
    key k2{42, 2};
    assert(k1 < k2);                                   // <-- error: three-way comparison of ‘key::secondary’ has type ‘std::partial_ordering’, which does not convert to ‘std::strong_ordering’
    return 0;
}
