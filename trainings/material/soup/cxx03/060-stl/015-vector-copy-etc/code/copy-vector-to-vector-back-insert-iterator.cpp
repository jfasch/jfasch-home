#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> src = {100, 200, 300};
    std::vector<int> dst;                             // <-- empty

    std::copy(src.begin(), src.end(),
              std::back_insert_iterator<std::vector<int>>(dst));

    for (int i: dst)
        std::cout << i << std::endl;

    return 0;
}
