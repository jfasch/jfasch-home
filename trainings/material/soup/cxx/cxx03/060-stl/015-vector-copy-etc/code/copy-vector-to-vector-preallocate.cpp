#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> src = {100, 200, 300};
    std::vector<int> dst(src.size());                 // <-- initialize dst to contain three default-constructed elements

    std::copy(src.begin(), src.end(), dst.begin());   // <--- those are overwritten here
    for (int i: dst)
        std::cout << i << std::endl;

    return 0;
}
