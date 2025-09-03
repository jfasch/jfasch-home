#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> src = {100, 200, 300};
    std::vector<int> dst;

    dst.reserve(src.size());                        // <--- makes dst contain three default-constructed element

    std::copy(src.begin(), src.end(), dst.begin()); // <--- those are overwritten here
    for (int i: dst)
        std::cout << i << std::endl;

    return 0;
}
