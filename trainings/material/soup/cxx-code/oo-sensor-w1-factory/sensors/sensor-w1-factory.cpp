#include "sensor-w1-factory.h"

#include <string>


W1Sensor* W1SensorFactory::find_by_address(uint64_t address) const
{
    std::filesystem::path devices_dir = _w1_fs_root / "devices";
    auto diriter = std::filesystem::directory_iterator(devices_dir);
    for (const auto& entry: diriter) {
        if (! entry.is_directory())
            continue;
        std::string filename = entry.path().filename();
        size_t pos = filename.find("-");
        if (pos == std::string::npos)
            continue;
        if (pos != 2)
            continue;
        std::string addr_str = filename.substr(pos+1, filename.size());
        uint64_t addr = std::stoul(addr_str, 0, 16);
        if (addr == address)
            return new W1Sensor(devices_dir / filename / "temperature");
    }

    return nullptr;
}
