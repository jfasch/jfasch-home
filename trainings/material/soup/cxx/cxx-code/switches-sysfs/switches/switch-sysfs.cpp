#include "switch-sysfs.h"

#include <hal-fileutil.h>
#include <hal-delay.h>

#include <cassert>
#include <filesystem>
namespace fs = std::filesystem;


static const std::filesystem::path basedir = "/sys/class/gpio";

SysFSSwitch::SysFSSwitch(int gpionr)
: _gpionr(gpionr)
{
    std::ostringstream s;
    s << "gpio" << _gpionr;

    _gpiodir = basedir / s.str();
}

void SysFSSwitch::export_and_configure()
{
    fs::path exportfile = basedir / "export";
    jf::hal::write_to_file_int(exportfile, _gpionr);

    // wait for gpiodir to appear. sadly, this is an asynchronous
    // operation.
    do {
        jf::hal::delay_ms(5);
        if (fs::exists(_gpiodir))
            break;
    } while (true);

    fs::path directionfile = _gpiodir / "direction";
    jf::hal::write_to_file(directionfile, "out");
}

void SysFSSwitch::unexport()
{
    std::filesystem::path unexportfile = basedir / "unexport";
    jf::hal::write_to_file_int(unexportfile, _gpionr);
}
    
Switch::State SysFSSwitch::state() const
{
    fs::path valuefile = _gpiodir / "value";
    int value = jf::hal::read_from_file_int(valuefile);
    switch (value) {
        case 0:
            return Switch::State::OFF;
        case 1:
            return Switch::State::ON;
    }
    assert(!"bad value found in value-file");
    return Switch::State::ON;
}

void SysFSSwitch::on()
{
    fs::path valuefile = _gpiodir / "value";
    jf::hal::write_to_file_int(valuefile, 1);
}

void SysFSSwitch::off()
{
    fs::path valuefile = _gpiodir / "value";
    jf::hal::write_to_file_int(valuefile, 0);
}
