#include <unistd.h>

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    cout << "PID: " << getpid() << endl;               // <--- self's PID
    cout << "PPID: " << getppid() << endl;             // <--- parent's PID

    return 0;
}
