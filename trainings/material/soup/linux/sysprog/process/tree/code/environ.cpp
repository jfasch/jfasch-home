#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    const char* path = getenv("PATH");                 // <--- PATH environment variable
    const char* home = getenv("HOME");                 // <--- HOME environment variable
    const char* user = getenv("USER");                 // <--- USER environment variable
    const char* customvar = getenv("CUSTOMVAR");       // <--- CUSTOMVAR environment variable

    cout << "PATH: " << path << endl;
    cout << "HOME: " << home << endl;
    cout << "USER: " << user << endl;
    if (customvar != NULL)
        cout << "CUSTOMVAR: " << customvar << endl;
    else
        cout << "CUSTOMVAR not set" << endl;

    return 0;
}
