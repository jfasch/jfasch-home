#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;


int main(void)
{
    cout << getpid() << endl;
    pause();
    return 0;
}
