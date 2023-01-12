#include <vector>
#include <iterator>
#include <iostream>
   
int main()
{
    std::vector<int> src = {100, 200, 300};
    std::copy(src.begin(), src.end(), std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}
