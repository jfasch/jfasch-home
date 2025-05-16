#include <iostream>

unsigned foo()
{
    return 42;
}

int main()
{
    if (unsigned f = foo(); f%2==0)
        std::cout << "foo returned " << f << " which is even\n";
    else
        std::cout << "foo returned " << f << " which is odd\n";
    // std::cout << "foo returned " << f << '\n';      // <-- f only valid in if/else
    return 0;
}
