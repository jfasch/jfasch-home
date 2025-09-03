#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> a = {100, 200, 300};

    const int *begin = &a[0];              // <--- pointer to first element
    const int *end = &a[3];                // <--- pointer past last element

    while (begin != end)
        std::cout << *begin++ << std::endl;

    return 0;
}
