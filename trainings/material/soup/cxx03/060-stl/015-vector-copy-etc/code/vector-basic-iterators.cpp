#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> a = {100, 200, 300};

    std::vector<int>::const_iterator begin = a.begin();  // <--- looks like a pointer, but isn't
    std::vector<int>::const_iterator end = a.end();      // <--- looks like a pointer, but isn't

    while (begin != end)
        std::cout << *begin++ << std::endl;

    return 0;
}
