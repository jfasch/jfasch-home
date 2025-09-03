#include <switch-sysfs.h>

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char** argv)
{
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <gpio#> {on|off}" << endl;
        return 1;
    }

    int gpionr = stoi(argv[1]);
    string onoff = argv[2];
    if (! (onoff == "on" || onoff == "off")) {
        cerr << "Usage: " << argv[0] << " <gpio#> {on|off}" << endl;
        return 1;
    }

    SysFSSwitch sw(gpionr);
    sw.export_and_configure();

    if (onoff == "on")
        sw.on();
    else 
        sw.off();

    sw.unexport();
    return 0;
}
