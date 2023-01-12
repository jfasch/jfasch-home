#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> a = {100, 200, 300};
    for (int i: a)                           // <--- range based for
        std::cout << i << std::endl;
    return 0;
}
