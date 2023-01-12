#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> src = {100, 200, 300};
    std::vector<int> dst(src.size());                 // <-- preallocate just enough memory

    std::copy(src.begin(), src.end(), dst.begin());
    for (int i: dst)
        std::cout << i << std::endl;

    return 0;
}
