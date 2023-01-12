#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> src = {100, 200, 300};
    int dst[3];

    std::copy(src.begin(), src.end(), dst);
    for (int i: dst)
        std::cout << i << std::endl;

    return 0;
}
