// was that to quickly demonstrate the std::hex modifier?

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::hex;
using std::setw;


int main()
{
    cout << setw(10) << hex << 42 << endl;
    printf("%x\n", 42);
}
