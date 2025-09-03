#include <vector>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
   
int main()
{
    std::vector<int> src = {100, 200, 300};
    std::vector<int> dst;                             // <--- ATTENTION: empty!!

    std::copy(src.begin(), src.end(), dst.begin());   // <--- CRASH!
    for (int i: dst)
        std::cout << i << std::endl;

    return 0;
}

#pragma GCC diagnostic pop
