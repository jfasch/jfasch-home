#include <set>
#include <cassert>

struct key
{
    unsigned id;
};

int main()
{
    std::set<key> my_keys;
    auto [_, inserted] = my_keys.insert({1});          // <-- error: no match for ‘operator<’
    assert(inserted);

    return 0;
}
