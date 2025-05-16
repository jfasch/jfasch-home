#include <set>
#include <cassert>

struct key
{
    unsigned id;
    bool operator<(const key& rhs) const
    {
        return id < rhs.id;                            // <-- annoying (and error-prone)
    }
};

int main()
{
    std::set<key> my_keys;
    auto [_, inserted] = my_keys.insert({1});
    assert(inserted);

    return 0;
}
