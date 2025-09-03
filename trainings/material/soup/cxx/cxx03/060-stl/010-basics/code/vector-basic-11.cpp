#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> a = {100, 200, 300};
        
    for (size_t i=0; i<a.size(); ++i)  // <--- index based iteration
        std::cout << a[i] << std::endl;

    return 0;
}
