#include <vector>
#include <iostream>
   
int main()
{
    std::vector<int> a;                // <--- C++98: initialization -> empty
    a.push_back(100);                  // <--- elements come during runtime
    a.push_back(200);                  // <--- ...
    a.push_back(300);                  // <--- ...
        
    for (size_t i=0; i<a.size(); ++i)  // <--- index based iteration
        std::cout << a[i] << std::endl;

    return 0;
}
