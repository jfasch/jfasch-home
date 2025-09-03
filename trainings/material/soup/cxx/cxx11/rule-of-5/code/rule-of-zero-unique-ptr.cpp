#include <iostream>
#include <memory>

class Owner
{
public:
    Owner() = default;
    Owner(std::unique_ptr<int>&& value)
    : _member(std::move(value)) {}
    /*empty*/                                          // <-- no copy, no move, no dtor
    const std::unique_ptr<int>& member() const { return _member; }
private:
    std::unique_ptr<int> _member;
};

int main()
{
    Owner orig(std::make_unique<int>(42));
    // Foo copy = orig;                                // <-- no
    Owner moved = std::move(orig);                     // <-- move ctor
    
    return 0;
}
