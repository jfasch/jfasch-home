#include <iostream>
#include <string>

class Owner
{
public:
    Owner() = default;
    Owner(const std::string& value)                    // <-- copies value
    : _member(value) {}
    Owner(std::string&& value)                         // <-- moves value
    : _member(std::move(value)) {}

    /*empty*/                                          // <-- no copy, no move, no dtor

    const std::string& member() const { return _member; }
private:
    std::string _member;
};

int main()
{
    Owner orig("howdy");                               // <-- moves temporary std::string object into orig

    {
        Owner copy1 = orig;                            // <-- copy ctor
        Owner copy2;
        copy2 = orig;                                  // <-- copy assignment operator

        std::cout << "COPY >>>" << '\n';
        std::cout << "orig: " << orig.member() << '\n';
        std::cout << "copy1: " << copy1.member() << '\n';
        std::cout << "copy2: " << copy2.member() << '\n';
    }
    {
        std::cout << "MOVE >>>" << '\n';
        Owner moved1 = std::move(orig);                // <-- move ctor
        std::cout << "orig: " << orig.member() << '\n';// <-- gone ...
        std::cout << "moved1: " << moved1.member() << '\n';     // ... moved here
        Owner moved2;
        moved2 = std::move(moved1);                    // <-- move assignment operator
        // ...
    }        

    return 0;
}
